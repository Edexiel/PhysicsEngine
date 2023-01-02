#include "System/TransformSystem.hpp"

#include "Components/Shape.hpp"
#include "Components/Transform.hpp"

#include "flecs.h"

void PhysicsEngine::TransformSystem::RegisterSystem(flecs::world &ecs)
{

    ecs.system<Shape::TransformedPoints, const Shape::Points, const Transform::Position, const Transform::Rotation>(
                    "Transform")
            .each([](Shape::TransformedPoints &tp,
                     const Shape::Points &p,
                     const Transform::Position &pos,
                     const Transform::Rotation &r) {

                for (int i = 0; i < p.points.size(); ++i)
                {
                    tp.points[i] = Vector2Add(pos.position, Vector2Rotate(p.points[i], r.rotation));
                }
            });


}
