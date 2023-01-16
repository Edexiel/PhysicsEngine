#include <iostream>
#include "System/TransformSystem.hpp"

#include "Components/Shape.hpp"
#include "Components/Transform.hpp"
#include "raymath.h"


PhysicsEngine::TransformSystem::TransformSystem(flecs::world &ecs) : System(ecs)
{

    _system = ecs.system<Shape::Points, const Transform::Position, const Transform::Rotation>("Transform")
            .each([](flecs::entity e,
                     Shape::Points &p,
                     const Transform::Position &pos,
                     const Transform::Rotation &r) {

//                TraceLog(LOG_INFO, "Running Transform system");

                flecs::vector<Vector2> tp{};

                for (auto point: p.points)
                {
                    tp.add(Vector2Add(pos.position, Vector2Rotate(point, r.rotation)));
                }


                e.set<Shape::TransformedPoints>({tp});


            });


}
void PhysicsEngine::TransformSystem::Run()
{
    System::Run();
}
