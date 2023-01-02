#ifndef PHYSICSENGINE_SCENE_HPP
#define PHYSICSENGINE_SCENE_HPP

namespace PhysicsEngine
{
    class World;

    class Scene
    {
    protected:
        World &_world;
        explicit Scene(World &world);

    public:
        Scene() = delete;
        virtual void Create();
    };
}
#endif //PHYSICSENGINE_SCENE_HPP
