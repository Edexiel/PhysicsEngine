#ifndef PHYSICSENGINE_SCENEMANAGER_H
#define PHYSICSENGINE_SCENEMANAGER_H

#include <stdint.h>
#include <vector>

namespace PhysicsEngine
{
    class Scene;

    class World;

    class SceneManager
    {
    private:
        uint32_t _index = 0;
        std::vector<Scene *> _scenes;
        World &_world;

    public:
        SceneManager() = delete;
        ~SceneManager();
        explicit SceneManager(World &world);


        void LoadScene(uint32_t index);
        inline void Reload() { LoadScene(_index); }
        inline uint32_t GetSceneIndex() const { return _index; }

        template<class SceneType, typename ... Types>
        void AddScene(World &world, Types... t);
    };

    template<class SceneType, typename ... Types>
    void SceneManager::AddScene(World &world, Types... t)
    {
        TraceLog(LOG_INFO, "Adding new scene");

        _scenes.push_back(new SceneType{world, t...});

    }
}
#endif //PHYSICSENGINE_SCENEMANAGER_HS
