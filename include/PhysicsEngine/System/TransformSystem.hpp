#ifndef PHYSICSENGINE_TRANSFORM_SYSTEM_HPP
#define PHYSICSENGINE_TRANSFORM_SYSTEM_HPP

#include "System.hpp"

namespace PhysicsEngine
{
    class TransformSystem : public System
    {
    public:

        explicit TransformSystem(flecs::world &world);

        void Run() override;

    };
}

#endif //PHYSICSENGINE_TRANSFORM_SYSTEM_HPP
