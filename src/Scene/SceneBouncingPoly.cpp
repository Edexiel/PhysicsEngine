#include "Scene/SceneBouncingPoly.hpp"

#include "raylib.h"
#include "flecs.h"

#include "Components/Shape.hpp"
#include "Components/RigidBody.hpp"
#include "Components/Transform.hpp"

PhysicsEngine::SceneBouncingPoly::SceneBouncingPoly(World &world, int polycount,
                                                    const Shape::RandomPolyParams &polyParams) :
        Scene(),
        _polycount(polycount),
        _polyParams(polyParams) {}


void PhysicsEngine::SceneBouncingPoly::Create(flecs::world &ecs, const World& world)
{
    Scene::Create(ecs, world);


    TraceLog(LOG_INFO, "Creating scene bouncingPoly");

    for (int i = 0; i < _polycount; ++i)
    {
        Vector2 position;
        Vector2 velocity;
        float rotation;

        Rectangle boundingBox;

        flecs::vector<Vector2> shape = PhysicsEngine::Shape::GetRandomPoly(_polyParams, position, velocity, rotation);

        ecs.entity()
                .set<Transform::Position>({position})
                .set<Transform::Rotation>({rotation})
                .set<Shape::Points>({shape})
                .set<Shape::TransformedPoints>({})
                .set<RigidBody::Velocity>({velocity})
                .set<RigidBody::AABB>({});
    }

}
void PhysicsEngine::SceneBouncingPoly::Update(flecs::world&ecs,const World& world)
{
    Scene::Update(ecs,world);
}
PhysicsEngine::SceneBouncingPoly::~SceneBouncingPoly() = default;