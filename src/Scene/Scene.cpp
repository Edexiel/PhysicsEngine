#include "Scene/Scene.hpp"

#include "System/DrawSystem.hpp"
#include "System/TransformSystem.hpp"
#include "System/AABBGenerationSystem.hpp"
#include "System/InputSystem.hpp"
#include "System/BroadPhaseSystem.hpp"

#include "raylib.h"
#include "flecs.h"


void PhysicsEngine::Scene::Create(flecs::world &ecs, const World &world)
{
    TraceLog(LOG_INFO, "Creating base scene");

    _inputSystem = new InputSystem(ecs);
    _transformSystem = new TransformSystem(ecs);
    _aabbSystem = new AABBGenerationSystem(ecs);
    _broadPhaseSystem = new BroadPhaseSystem(ecs);
//    _narrowPhaseSystem = new NarrowPhaseSystem(ecs);

    _drawsystem = new DrawSystem(ecs, world.debug);

}
void PhysicsEngine::Scene::Update(const World &world)
{

    _inputSystem->Run();

    _transformSystem->Run();
    _aabbSystem->Run();

    _timer.Start();
    _broadPhaseSystem->Run();
    _timer.Stop();

    if (world.debug)
    {
        std::basic_string<char> message = _timer.GetStringDuration("Broad phase :");
        DrawText(message.c_str(), 5, (int) world.screen.y - 40, 20, LIME);
    }

//    _timer.Start();
//    _narrowPhaseSystem->Run();
//    _timer.Stop();
//    if (world.debug)
//    {
//        std::basic_string<char> message = _timer.GetStringDuration("Systems :");
//        DrawText(message.c_str(), 5, (int) screenSize.y - 60, 20, LIME);
//    }

    _drawsystem->Run();

}

PhysicsEngine::Scene::~Scene()
{
    delete _drawsystem;
    delete _transformSystem;
    delete _aabbSystem;
    delete _inputSystem;
    delete _broadPhaseSystem;
}

