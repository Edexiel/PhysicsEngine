#include "System/AABBGenerationSystem.hpp"
#include <cfloat>
#include <iostream>

#include "Components/RigidBody.hpp"
#include "Components/Transform.hpp"
#include "Components/Shape.hpp"

#include "raymath.h"

PhysicsEngine::AABBGenerationSystem::AABBGenerationSystem(flecs::world &ecs) : System(ecs)
{
    // Generate AABB
    _system = ecs.system<const Transform::Rotation, Shape::TransformedPoints>("GenerateAABB")
            .each([](flecs::entity e, const Transform::Rotation &r, Shape::TransformedPoints &p) {

//                TraceLog(LOG_INFO, "Running AABB system");
//                std::cout<<e.name()<<std::endl;
                Rectangle boundingBox;

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

                e.set<RigidBody::AABB>({boundingBox});

            });
}
void PhysicsEngine::AABBGenerationSystem::Run()
{
//    System::Run();
    _system.run();
}
