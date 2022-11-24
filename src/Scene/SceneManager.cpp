#include "raylib.h"

#include "Scene/SceneManager.hpp"
#include "Scene/SceneBase.hpp"
#include "Scene/World.hpp"
#include "Scene/SceneBouncingPoly.hpp"


SceneManager::SceneManager(World &world) : _world(world) {}
SceneManager::~SceneManager()
{
    _scenes.clear();
}


void SceneManager::LoadScene(uint32_t index)
{
    if (index > _scenes.size()-1)
    {
        TraceLog(LOG_ERROR, "Requested scene number is greater than total scenes");
        return;
    }
    TraceLog(LOG_ALL, "TEST");
    _world.Clear();

    _scenes[index]->Create();
    _index = index;

}



