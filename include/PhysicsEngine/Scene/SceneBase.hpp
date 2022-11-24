#ifndef PHYSICSENGINE_SCENEBASE_HPP
#define PHYSICSENGINE_SCENEBASE_HPP

class World;

class SceneBase
{
protected:
    World &_world;
    explicit SceneBase(World &world);

public:
    SceneBase() = delete;
    virtual void Create();
};


#endif //PHYSICSENGINE_SCENEBASE_HPP
