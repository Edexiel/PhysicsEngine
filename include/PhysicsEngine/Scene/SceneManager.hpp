#ifndef PHYSICSENGINE_SCENEMANAGER_H
#define PHYSICSENGINE_SCENEMANAGER_H

#include <stdint.h>
#include <vector>

class SceneBase;

class World;

class SceneManager
{
private:
    uint32_t _index = 0;
    std::vector<SceneBase *> _scenes;
    World &_world;

public:
    SceneManager() = delete;
    ~SceneManager();
    explicit SceneManager(World &world);


    void LoadScene(uint32_t index);
    inline void Reload() { LoadScene(_index); }
    inline uint32_t GetCurrentSceneIndex() const { return _index; }

    template<class SceneType, typename ... Types>
    void AddScene(World &world, Types... t);
};

template<class SceneType, typename ... Types>
void SceneManager::AddScene(World &world, Types... t)
{
    TraceLog(LOG_INFO, "Adding new scene");

    _scenes.push_back(new SceneType{world, t...});

}
#endif //PHYSICSENGINE_SCENEMANAGER_HS
