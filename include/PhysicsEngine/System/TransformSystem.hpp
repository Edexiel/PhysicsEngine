#include "System.hpp"

#ifndef PHYSICSENGINE_TRANSFORM_SYSTEM_HPP
#define PHYSICSENGINE_TRANSFORM_SYSTEM_HPP

namespace PhysicsEngine
{
    class TransformSystem : public System
    {
    public:

        explicit TransformSystem(World &world) : System(world) {}

        void RegisterSystem(flecs::world &ecs) override;

    };
}

#endif //PHYSICSENGINE_TRANSFORM_SYSTEM_HPP
