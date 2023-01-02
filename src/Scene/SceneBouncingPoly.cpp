#include "Scene/SceneBouncingPoly.hpp"

#include "raylib.h"
#include "World.hpp"
#include "System/InputSystem.hpp"
#include "flecs.h"

#include "Components/Shape.hpp"
#include "Components/RigidBody.hpp"
#include "Components/Transform.hpp"

PhysicsEngine::SceneBouncingPoly::SceneBouncingPoly(World &world, int polycount,
                                                    const Shape::RandomPolyParams &polyParams) :
        Scene(world), _polycount(polycount), _polyParams(polyParams) {}


void PhysicsEngine::SceneBouncingPoly::Create()
{
    Scene::Create();

    TraceLog(LOG_INFO, "Creating scene bouncingPoly");

    flecs::world * w = _world._ecs;

    for (int i = 0; i < _polycount; ++i)
    {
        Vector2 position;
        Vector2 velocity;
        float rotation;
        std::vector<Vector2> shape;
        Rectangle boundingBox;

        PhysicsEngine::Shape::GetRandomPoly(_polyParams, position, velocity, rotation, shape);

        w->entity()
                .set<Transform::Position>({position})
                .set<Transform::Rotation>({rotation})
                .set<Shape::Points>({shape})
                .set<Shape::TransformedPoints>({})
                .set<RigidBody::Velocity>({velocity})
                .set<RigidBody::AABB>({});
    }

//    w.system<>.kind(flecs::PreUpdate).each();
    _world.AddSystem<InputSystem>();

}
