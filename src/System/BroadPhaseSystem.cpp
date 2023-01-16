#include "System/BroadPhaseSystem.hpp"


#include "Components/RigidBody.hpp"
#include "flecs.h"
#include "Tools/Maths.hpp"
#include "Components/Transform.hpp"


PhysicsEngine::BroadPhaseSystem::BroadPhaseSystem(flecs::world &ecs) : System(ecs)
{

    _system = ecs.system<const RigidBody::AABB>("BroadPhaseSystem")
            .order_by<const RigidBody::AABB>(
                    [](flecs::entity_t e1, const RigidBody::AABB *a, flecs::entity_t e2, const RigidBody::AABB *b) {
                        return (a->aabb.x > b->aabb.x) - (a->aabb.x < b->aabb.x);
                    })
            .iter([](flecs::iter &it, const RigidBody::AABB *aabbs) {

//                TraceLog(LOG_INFO, "Running AABB system");


                for (int i = 0; i < it.count(); ++i)
                {
                    const Rectangle &rec = aabbs[i].aabb;

                    for (int j = i + 1; j < it.count(); ++j)
                    {
                        const Rectangle &nextRec = aabbs[j].aabb;
                        if (nextRec.x > (rec.x + rec.width))
                        {
                            // No chance of collision on x-axis
                            break;
                        }

                        if (Maths::AABBCollideY(rec, nextRec))
                        {
                            TraceLog(LOG_INFO, "Collision!!!!!");
                        }
                    }
                }
            });
}
void PhysicsEngine::BroadPhaseSystem::Run()
{
    System::Run();
}
