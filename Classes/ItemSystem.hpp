/*
Copyright (c) 2018 Inverse Palindrome
Apophis - ItemSystem.hpp
InversePalindrome.com
*/


#pragma once

#include "Events.hpp"
#include "EntityParser.hpp"

#include <entityx/System.h>

#include <cpptime.h>


class ItemSystem : public entityx::System<ItemSystem>, public entityx::Receiver<ItemSystem>
{
public:
	explicit ItemSystem(EntityParser& entityParser);

	virtual void configure(entityx::EventManager& eventManager) override;
	virtual void update(entityx::EntityManager& entityManager, entityx::EventManager& eventManager, entityx::TimeDelta deltaTime) override;
	virtual void receive(const EntityDied& event);
	virtual void receive(const PickedUpItem& event);

private:
	EntityParser& entityParser;
	entityx::EventManager* eventManager;

	CppTime::Timer timer;

	void addWeapon(entityx::Entity entity, entityx::Entity itemEntity);
	void addRegenBoost(entityx::Entity entity, entityx::Entity itemEntity);
	void addSpeedBoost(entityx::Entity entity, entityx::Entity itemEntity);
};