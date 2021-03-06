/*
Copyright (c) 2018 Inverse Palindrome
Apophis - BodyComponent.hpp
InversePalindrome.com
*/


#pragma once

#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2d/Dynamics/Joints/b2Joint.h>
#include <Box2D/Collision/Shapes/b2EdgeShape.h>
#include <Box2D/Collision/Shapes/b2ChainShape.h>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>

#include <pugixml.hpp>

#include <vector>
#include <variant>


class BodyComponent
{
public:
    BodyComponent();

    void load(const pugi::xml_node& componentNode);
    void save(pugi::xml_node& componentNode) const;

    void display();

    b2Body* getBody();
    void setBody(b2Body* body);

    b2Fixture* getFixtureList();
    const b2Fixture* getFixtureList() const;

    b2JointEdge* getJointList();
    const b2JointEdge* getJointList() const;

    void* getUserData() const;
    void setUserData(void* userData);

    b2BodyType getBodyType() const;
    void setBodyType(b2BodyType bodyType);

    b2Vec2 getPosition() const;
    void setPosition(const b2Vec2& position);

    b2Vec2 getLinearVelocity() const;
    void setLinearVelocity(const b2Vec2& linearVelocity);

    float getAngularVelocity() const;
    void setAngularVelocity(float angularVelocity);

    float getAngle() const;
    void setAngle(float angle);

    float getMass() const;
    float getInertia() const;

    float getLinearDamping() const;
    void setLinearDamping(float linearDamping);

    float getAngularDamping() const;
    void setAngularDamping(float angularDamping);

    b2AABB getAABB() const;
    void computeAABB();

    b2Fixture* createFixture(const b2FixtureDef& fixtureDef);
    void destroyFixture(b2Fixture* fixture);

    void applyLinearImpulse(const b2Vec2& linearImpulse);
    void applyAngularImpulse(float angularImpulse);

    void applyLinearForce(const b2Vec2& linearForce);
    void applyAngularForce(float angularForce);

    bool isRotationFixed() const;
    void setRotationFixed(bool rotationFixed);

    bool isBullet() const;
    void setBullet(bool bullet);

    bool contains(const b2Vec2& point) const;
    bool raycast(b2RayCastOutput& output, const b2RayCastInput& input) const;

private:
    b2Body* body;

    b2AABB AABB;

    int shapeIndex;
    int polygonModeIndex;
    int chainModeIndex;
    std::variant<b2CircleShape, b2EdgeShape, b2PolygonShape, b2ChainShape> shape;

    b2Vec2 box;
    std::vector<b2Vec2> vertices;
};