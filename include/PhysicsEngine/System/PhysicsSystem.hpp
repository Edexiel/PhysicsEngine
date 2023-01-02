#ifndef PHYSICSENGINE_PHYSICSSYSTEM_HPP
#define PHYSICSENGINE_PHYSICSSYSTEM_HPP

#include "System.hpp"

class Rectangle;

namespace PhysicsEngine
{
    class PhysicsSystem : public System
    {
    public:
        explicit PhysicsSystem(World &world) : System(world) {};

        void RegisterSystem(flecs::world &ecs) override;
    };
}

#endif //PHYSICSENGINE_PHYSICSSYSTEM_HPP
