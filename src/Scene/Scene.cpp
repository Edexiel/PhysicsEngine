#include "Scene/Scene.hpp"
#include "World.hpp"
#include <System/DrawSystem.hpp>

#include "Components/Transform.hpp"
#include "Components/RigidBody.hpp"
#include "Components/Shape.hpp"

PhysicsEngine::Scene::Scene(World &world) : _world(world) {}

void PhysicsEngine::Scene::Create()
{
    TraceLog(LOG_INFO, "Creating base scene");
}

