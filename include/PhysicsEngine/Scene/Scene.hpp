#ifndef PHYSICSENGINE_SCENE_HPP
#define PHYSICSENGINE_SCENE_HPP


#include "Time/Timer.hpp"

namespace flecs
{
    struct world;
}

struct World
{
    bool &debug;

    class Vector2 &screen;
};

namespace PhysicsEngine
{
    class Scene
    {
    protected:
        Timer _timer{};

        class TransformSystem *_transformSystem = nullptr;

        class AABBGenerationSystem *_aabbSystem = nullptr;

        class DrawSystem *_drawsystem = nullptr;

        class InputSystem *_inputSystem = nullptr;

        class BroadPhaseSystem *_broadPhaseSystem = nullptr;

        class NarrowPhaseSystem *_narrowPhaseSystem = nullptr;


        explicit Scene() = default;

    public:
        ~Scene();
        virtual void Create(flecs::world &ecs, const World &world);
        virtual void Update(flecs::world &ecs, const World &world);
    };
}
#endif //PHYSICSENGINE_SCENE_HPP
