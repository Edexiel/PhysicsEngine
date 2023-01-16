#ifndef PHYSICSENGINE_SYSTEM_HPP
#define PHYSICSENGINE_SYSTEM_HPP

#include <vector>
#include "flecs.h"

namespace PhysicsEngine
{

    class System
    {
    protected:
        flecs::world &_ecs;
        flecs::system _system;

        explicit System(flecs::world &ecs);

    public:
        System() = delete;

        virtual void Run();

    };
}

#endif //PHYSICSENGINE_SYSTEM_HPP
