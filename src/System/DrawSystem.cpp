#include <iostream>
#include "System/DrawSystem.hpp"


#include "Components/Shape.hpp"
#include "Components/RigidBody.hpp"

#include "flecs.h"
#include "raylib.h"


PhysicsEngine::DrawSystem::DrawSystem(flecs::world &ecs, bool &debug) : System(ecs), _debug(debug)
{
    TraceLog(LOG_INFO, "Registering draw system");

    _system = ecs.system<Shape::TransformedPoints, const Shape::VertexColor, const RigidBody::AABB>("Draw")
            .each([&debug = _debug](
                    flecs::entity e,
                    Shape::TransformedPoints &tp,
                    const Shape::VertexColor &vertexColor,
                    const RigidBody::AABB &AABB) {

//                TraceLog(LOG_INFO, "Running draw system");

                flecs::vector<Vector2> &points = tp.points;

                DrawLineStrip(&points[0], (int) points.count(), vertexColor.color);
                DrawLineV(points[0], points[points.count() - 1], vertexColor.color);

                // If debug mode is on we draw the AABB
                if (debug)
                {
                    const Rectangle &temp = AABB.aabb;
                    const Color color = LIME;//object.collide ? ORANGE : LIME;

//                    if (e.is_pair())
//                    {
//                        TraceLog(LOG_INFO, "POUET");
//
//                    }

                    DrawLine(temp.x, temp.y, temp.x + temp.width, temp.y, color); //top
                    DrawLine(temp.x, temp.y + temp.height, temp.x + temp.width, temp.y + temp.height, color); //top
                    DrawLine(temp.x, temp.y, temp.x, temp.y + temp.height, color); //left
                    DrawLine(temp.x + temp.width, temp.y, temp.x + temp.width, temp.y + temp.height, color); //right

                }

            });
}
void PhysicsEngine::DrawSystem::Run()
{
    System::Run();
}
