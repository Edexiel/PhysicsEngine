#include "raylib.h"

#include "Scene/SceneManager.hpp"
#include "Scene/Scene.hpp"
#include "World.hpp"
#include "Scene/SceneBouncingPoly.hpp"


PhysicsEngine::SceneManager::SceneManager(World &world) : _world(world) {}
PhysicsEngine::SceneManager::~SceneManager()
{
    for (Scene *scene: _scenes)
    {
        delete scene;
    }
    _scenes.clear();
}


void PhysicsEngine::SceneManager::LoadScene(uint32_t index)
{
    if (index > _scenes.size() - 1)
    {
        TraceLog(LOG_ERROR, "Requested scene number is greater than total scenes");
        return;
    }
    TraceLog(LOG_ALL, "TEST");
    _world.Clear();

    _scenes[index]->Create();
    _index = index;

}



