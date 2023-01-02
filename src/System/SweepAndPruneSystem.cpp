#include "System/SweepAndPruneSystem.hpp"


#include "Components/RigidBody.hpp"
//#include "Components/Transform.hpp"
//#include "raylib.h"
#include "flecs.h"

int sort(flecs::entity_t e1, const PhysicsEngine::RigidBody::AABB *a, flecs::entity_t e2,
         const PhysicsEngine::RigidBody::AABB *b)
{

    return (a->aabb.x > b->aabb.x) - (a->aabb.x < b->aabb.x);
}

void PhysicsEngine::SweepAndPruneSystem::RegisterSystem(flecs::world &ecs)
{
    auto q = ecs.query_builder<const RigidBody::AABB>()
            .order_by(sort).build();

}
