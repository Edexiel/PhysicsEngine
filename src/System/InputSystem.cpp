#include "System/InputSystem.hpp"
#include "raylib.h"

#include "Components/Transform.hpp"
#include "Components/RigidBody.hpp"

#include "flecs.h"

PhysicsEngine::InputSystem::InputSystem(flecs::world &ecs) : System(ecs)
{

}
void PhysicsEngine::InputSystem::Run()
{

    if (IsMouseButtonPressed(MouseButton::MOUSE_BUTTON_LEFT))
    {
        _ecs.each([](flecs::entity e, const RigidBody::AABB &aabb) {

            if (RigidBody::PointInsideAABB(aabb.aabb, GetMousePosition()))
            {
//                    TraceLog(LOG_INFO, "NEW TARGET");
                e.add<Target>();
            }
        });
    }
    if (IsMouseButtonReleased(MouseButton::MOUSE_BUTTON_LEFT))
    {
        _ecs.each([](flecs::entity e, const RigidBody::AABB &aabb) {
            if (e.has<Target>())
            {
                e.remove<Target>();
            }
        });;
    }

    if (IsMouseButtonDown(MouseButton::MOUSE_BUTTON_LEFT))
    {
        _ecs.each([](const Target &t, Transform::Position &p) {
            p.position = Transform::Move(p.position, GetMouseDelta());
        });
    }
}
