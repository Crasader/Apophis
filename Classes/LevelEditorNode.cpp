/*
Copyright (c) 2018 Inverse Palindrome
Apophis - LevelEditorNode.cpp
InversePalindrome.com
*/


#include "Components.hpp"
#include "LevelParser.hpp"
#include "PhysicsSystem.hpp"
#include "GraphicsSystem.hpp"
#include "LevelSerializer.hpp"
#include "LevelEditorNode.hpp"

#include "CCIMGUI.h"
#include "CCImGuiLayer.h"

#include <nfd.h>

#include <brigand/algorithms/for_each.hpp>


LevelEditorNode::LevelEditorNode() :
	entityManager(eventManager),
	systemManager(entityManager, eventManager),
	mapDimensions(0.f, 0.f)
{
}

bool LevelEditorNode::init()
{
	if (!Node::init())
	{
		return false;
	}

	scheduleUpdate();
	initSystems();

	auto* font = ImGui::GetIO().Fonts->AddFontFromFileTTF("Fonts/OpenSans-Regular.ttf", 40.f);

	CCIMGUI::getInstance()->addImGUI([this, font]()
	{
		ImGui::PushFont(font);

		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open"))
				{
					nfdchar_t* filename = nullptr;
					
					if (NFD_OpenDialog("xml", nullptr, &filename) == NFD_OKAY)
					{
						LevelParser::parseLevel(entityManager, eventManager, mapDimensions, filename);
					}
				}
				if (ImGui::MenuItem("Save"))
				{
					nfdchar_t* filename = nullptr;
					
					if (NFD_SaveDialog("xml", nullptr, &filename) == NFD_OKAY)
					{
						LevelSerializer::saveLevel(entities, mapDimensions, filename);
					}
				}

				ImGui::EndMenu();
			}

			ImGui::EndMainMenuBar();
		}

		ImGui::Begin("Entities");

		for (auto entity : entities)
		{
			if (ImGui::TreeNode(std::to_string(entity.id().index()).c_str()))
			{
				brigand::for_each<Components>([entity](auto componentElement) mutable
				{
					if (auto component = entity.component<decltype(componentElement)::type>())
					{
						component->display();
					}
				});

				ImGui::TreePop();
			}
		}

		ImGui::End();

		ImGui::PopFont();
	}, "LevelEditor");

	return true;
}

void LevelEditorNode::update(float dt)
{
	systemManager.update_all(dt);
}

void LevelEditorNode::receive(const entityx::EntityCreatedEvent& event)
{
	entities.push_back(event.entity);
}

void LevelEditorNode::receive(const entityx::EntityDestroyedEvent& event)
{
	entities.erase(std::remove(std::begin(entities), std::end(entities), event.entity), std::end(entities));
}

cocos2d::Scene* LevelEditorNode::scene()
{
	auto* scene = cocos2d::Scene::create();
	scene->addChild(LevelEditorNode::create());
	scene->addChild(ImGuiLayer::create());

	return scene;
}

void LevelEditorNode::initSystems()
{
	systemManager.add<GraphicsSystem>(this, mapDimensions);
	systemManager.add<PhysicsSystem>(entityManager, eventManager);

	eventManager.subscribe<entityx::EntityCreatedEvent>(*this);
	eventManager.subscribe<entityx::EntityDestroyedEvent>(*this);

	systemManager.configure();
}