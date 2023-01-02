#ifndef PHYSICSENGINE_SYSTEM_HPP
#define PHYSICSENGINE_SYSTEM_HPP

#include <vector>

namespace flecs
{
    struct world;
}


namespace PhysicsEngine
{
    class Object;

    class World;

    class System
    {
    protected:
        World &_world;

        explicit System(World &world) : _world(world) {};

    public:
        System() = delete;
        virtual ~System() = default;

        virtual void RegisterSystem(flecs::world &ecs) = 0;

    };
}

#endif //PHYSICSENGINE_SYSTEM_HPP
