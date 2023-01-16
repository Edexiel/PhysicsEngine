#ifndef PHYSICSENGINE_NarrowPhaseSystem_HPP
#define PHYSICSENGINE_NarrowPhaseSystem_HPP

#include "System.hpp"

namespace PhysicsEngine
{
    class NarrowPhaseSystem : public System
    {
    public:
        explicit NarrowPhaseSystem(flecs::world &ecs);
        void Run() override;
    };

} // AABBGenerationSystem

#endif //PHYSICSENGINE_NarrowPhaseSystem_HPP
