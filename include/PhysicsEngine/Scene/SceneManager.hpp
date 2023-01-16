#ifndef PHYSICSENGINE_SCENEMANAGER_H
#define PHYSICSENGINE_SCENEMANAGER_H

#include <stdint.h>
#include <vector>
#include "flecs.h"
#include "raylib.h"

#include "Scene.hpp"

namespace PhysicsEngine
{
    class Scene;

    class SceneManager
    {
    private:
        uint32_t _index = 0;
        std::vector<Scene *> _scenes;
        flecs::world *_ecs = nullptr;
        World &_world;

    public:
        explicit SceneManager(World &world) : _world(world) {};
        ~SceneManager();

        void LoadScene(uint32_t index);
        inline void Reload() { LoadScene(_index); }
        void Update();
        inline uint32_t GetSceneIndex() const { return _index; }

        template<class SceneType, typename ... Types>
        void AddScene(Types... t);
    };

    template<class SceneType, typename ... Types>
    void SceneManager::AddScene(Types... t)
    {
        TraceLog(LOG_INFO, "Adding new scene");

        _scenes.push_back(new SceneType{t...});

    }
}
#endif //PHYSICSENGINE_SCENEMANAGER_H
