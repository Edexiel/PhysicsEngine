#include "Scene/SceneDebug.hpp"

#include "raymath.h"

#include "World.hpp"

#include "Components/Shape.hpp"
#include "Components/RigidBody.hpp"
#include "Components/Transform.hpp"

#include "flecs.h"


PhysicsEngine::SceneDebug::SceneDebug(World &world) : Scene(world) {}

void PhysicsEngine::SceneDebug::Create()
{
    Scene::Create();

    TraceLog(LOG_INFO, "Creating scene bouncingPoly");

    const Vector2 &screen = _world.screenSize;

    flecs::world * w = _world._ecs;

    float rotation;
    std::vector<Vector2> points;

    PhysicsEngine::Shape::GetTriangle(300.0f, 200.0f, points);

    w->entity()
            .set<Transform::Position>({screen.x * 0.33f, screen.y / 2})
            .set<Transform::Rotation>({rotation})
            .set<Shape::Points>({points})
            .set<Shape::TransformedPoints>({})
            .set<RigidBody::Velocity>({Vector2Zero()})
            .set<RigidBody::AABB>({});

    PhysicsEngine::Shape::GetTriangle(250.0f, 200.0f, points);

    w->entity()
            .set<Transform::Position>({screen.x * 0.66f, screen.y / 2})
            .set<Transform::Rotation>({0})
            .set<Shape::Points>({points})
            .set<Shape::TransformedPoints>({})
            .set<RigidBody::Velocity>({Vector2Zero()})
            .set<RigidBody::AABB>({});


}
