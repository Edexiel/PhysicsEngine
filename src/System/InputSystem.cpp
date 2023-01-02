#include "System/InputSystem.hpp"
#include "raylib.h"

#include "Components/Transform.hpp"
#include "Components/RigidBody.hpp"

#include "flecs.h"

void PhysicsEngine::InputSystem::RegisterSystem(flecs::world &ecs)
{
    ecs.system<const RigidBody::AABB>("MousePick")
            .each([](flecs::entity e, const RigidBody::AABB &aabb) {

                if (aabb.PointInsideAABB(GetMousePosition()))
                {
                    TraceLog(LOG_INFO, "NEW TARGET");

                    e.add<Target>();
                }
            });

    ecs.system<const RigidBody::AABB>("MouseUnpick")
            .each([](flecs::entity e, const RigidBody::AABB &aabb) {
                if (e.has<Target>())
                {
                    e.remove<Target>();
                }
            });

    ecs.system<const Target, Transform::Position>("MouseMove")
            .each([](const Target &t, Transform::Position &p) {
                p.Move(GetMouseDelta());
            });


}