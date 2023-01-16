#include "System/System.hpp"

#include "flecs.h"

PhysicsEngine::System::System(flecs::world &ecs) : _ecs(ecs)
{}


void PhysicsEngine::System::Run()
{
    _system.run();
}
