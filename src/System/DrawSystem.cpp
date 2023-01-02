#include "System/DrawSystem.hpp"


#include "Components/Shape.hpp"
#include "Components/RigidBody.hpp"

#include "World.hpp"
#include "flecs.h"
#include "raylib.h"


void PhysicsEngine::DrawSystem::RegisterSystem(flecs::world &ecs)
{
    ecs.system<Shape::TransformedPoints, const Shape::VertexColor, const RigidBody::AABB>("Draw")
            .each([&debug = _debug](Shape::TransformedPoints &tp,
                                    const Shape::VertexColor &vertexColor,
                                    const RigidBody::AABB &AABB) {
                std::vector<Vector2> &points = tp.points;
                DrawLineStrip(points.data(), (int) points.size(), vertexColor.color);
                DrawLineV(points[0], points[points.size() - 1], vertexColor.color);

                if (debug)
                {
                    const Rectangle &temp = AABB.aabb;
                    const Color color = LIME;//object.collide ? ORANGE : LIME;

                    DrawLine(temp.x, temp.y, temp.x + temp.width, temp.y, color); //top
                    DrawLine(temp.x, temp.y + temp.height, temp.x + temp.width, temp.y + temp.height, color); //top
                    DrawLine(temp.x, temp.y, temp.x, temp.y + temp.height, color); //left
                    DrawLine(temp.x + temp.width, temp.y, temp.x + temp.width, temp.y + temp.height, color); //right

                }

            });
}

PhysicsEngine::DrawSystem::DrawSystem(PhysicsEngine::World &world) : System(world), _debug{world._debug} {}