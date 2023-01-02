#include <cfloat>
#include "System/PhysicsSystem.hpp"


#include "Components/RigidBody.hpp"
#include "Components/Transform.hpp"
#include "Components/Shape.hpp"

#include "flecs.h"
#include "raymath.h"

void PhysicsEngine::PhysicsSystem::RegisterSystem(flecs::world &ecs)
{
    ecs.system<RigidBody::AABB, const Transform::Rotation, const Shape::TransformedPoints>("GenerateAABB")
            .each([](RigidBody::AABB &b, const Transform::Rotation &r, const Shape::TransformedPoints &p) {

                Rectangle &boundingBox = b.aabb;

                boundingBox.x = FLT_MAX, boundingBox.y = FLT_MAX;
                float maxX{FLT_MIN}, maxY{FLT_MIN};

                for (const auto &point: p.points)
                {
                    Vector2 rotated{Vector2Rotate(point, r.rotation)};

                    if (rotated.x < boundingBox.x)
                        boundingBox.x = rotated.x;
                    if (rotated.x > maxX)
                        maxX = rotated.x;

                    if (rotated.y < boundingBox.y)
                        boundingBox.y = rotated.y;
                    if (rotated.y > maxY)
                        maxY = rotated.y;
                }

                boundingBox.width = maxX - boundingBox.x;
                boundingBox.height = maxY - boundingBox.y;

            });
}
