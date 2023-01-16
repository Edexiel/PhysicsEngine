#ifndef PHYSICSENGINE_AABBGENERATIONSYSTEM_HPP
#define PHYSICSENGINE_AABBGENERATIONSYSTEM_HPP

#include "System.hpp"

namespace PhysicsEngine
{
    class AABBGenerationSystem : public System
    {
    public:

        explicit AABBGenerationSystem(flecs::world &world);
        void Run() override;
    };
}

#endif //PHYSICSENGINE_AABBGENERATIONSYSTEM_HPP
