#include "Scene/SceneManager.hpp"
#include "Scene/Scene.hpp"

PhysicsEngine::SceneManager::~SceneManager()
{
    for (Scene *scene: _scenes)
        delete scene;

    _scenes.clear();
}


void PhysicsEngine::SceneManager::LoadScene(uint32_t index)
{
    if (index > _scenes.size() - 1)
    {
        TraceLog(LOG_ERROR, "Requested scene number is greater than total scenes");
        return;
    }

    delete _ecs;
    _ecs = new flecs::world;

    _scenes[index]->Create(*_ecs,_world);
    _index = index;

}
void PhysicsEngine::SceneManager::Update()
{
    _scenes[_index]->Update(_world);
}


