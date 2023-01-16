#ifndef PHYSICSENGINE_BROADPHASESYSTEM_HPP
#define PHYSICSENGINE_BROADPHASESYSTEM_HPP

#include "System.hpp"

namespace PhysicsEngine
{
    class BroadPhaseSystem : public System
    {
    public:
        explicit BroadPhaseSystem(flecs::world &ecs);
        void Run() override;
    };

} // AABBGenerationSystem

#endif //PHYSICSENGINE_BROADPHASESYSTEM_HPP
