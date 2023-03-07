#include "Scene/SceneDebug.hpp"
#include "Components/Shape.hpp"
#include "Components/Transform.hpp"

#include "flecs.h"


PhysicsEngine::SceneDebug::SceneDebug(World &world) : Scene() {}

void PhysicsEngine::SceneDebug::Create(flecs::world &ecs, const World &world)
{
    Scene::Create(ecs, world);

    TraceLog(LOG_INFO, "Creating scene debug");

//    float rotation=0;

    flecs::vector<Vector2> shape1 = PhysicsEngine::Shape::GetTriangle(300.0f, 200.0f);

    ecs.entity("Shape1")
            .set<Transform::Position>({world.screen.x * 0.33f, world.screen.y / 2})
            .set<Transform::Rotation>({0})
            .set<Shape::Points>({shape1})
            .set<Shape::VertexColor>({BLACK});

    flecs::vector<Vector2> shape2 = PhysicsEngine::Shape::GetTriangle(250.0f, 200.0f);

    ecs.entity("Shape2")
            .set<Transform::Position>({world.screen.x * 0.66f, world.screen.y / 2})
            .set<Transform::Rotation>({0})
            .set<Shape::Points>({shape2})
            .set<Shape::VertexColor>({BLACK});

//    flecs::vector<Vector2> shape3 = PhysicsEngine::Shape::GetTriangle(100.0f, 100.0f);
//
//    ecs.entity("Shape3")
//            .set<Transform::Position>({world.screen.x * 0.88f, world.screen.y / 2})
//            .set<Transform::Rotation>({0})
//            .set<Shape::Points>({shape3})
//            .set<Shape::VertexColor>({BLACK});


}
void PhysicsEngine::SceneDebug::Update(flecs::world&ecs,const World &world)
{
    Scene::Update(ecs,world);
}

