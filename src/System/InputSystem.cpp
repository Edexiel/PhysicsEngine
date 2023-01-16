#include "System/InputSystem.hpp"
#include "raylib.h"

#include "Components/Transform.hpp"
#include "Components/RigidBody.hpp"

#include "flecs.h"

PhysicsEngine::InputSystem::InputSystem(flecs::world &ecs) : System(ecs)
{
    _select = ecs.system<const RigidBody::AABB>("Select")
            .each([](flecs::entity e, const RigidBody::AABB &aabb) {

                if (RigidBody::PointInsideAABB(aabb.aabb, GetMousePosition()))
                {
//                    TraceLog(LOG_INFO, "NEW TARGET");
                    e.add<Target>();
                }
            });

    _unselect = ecs.system<const RigidBody::AABB>("Unselect")
            .each([](flecs::entity e, const RigidBody::AABB &aabb) {
                if (e.has<Target>())
                {
                    e.remove<Target>();
                }
            });

    _move = ecs.system<const Target, Transform::Position>("Move")
            .each([](const Target &t, Transform::Position &p) {
                p.position = Transform::Move(p.position, GetMouseDelta());
            });


}
void PhysicsEngine::InputSystem::Run()
{

    if (IsMouseButtonPressed(MouseButton::MOUSE_BUTTON_LEFT))
    {
        _select.run();
    }
    if (IsMouseButtonReleased(MouseButton::MOUSE_BUTTON_LEFT))
    {
        _unselect.run();
    }

    if (IsMouseButtonDown(MouseButton::MOUSE_BUTTON_LEFT))
    {
        _move.run();
    }
}
