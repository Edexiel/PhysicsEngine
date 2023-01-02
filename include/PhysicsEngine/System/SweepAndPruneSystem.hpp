#ifndef PHYSICSENGINE_SWEEPANDPRUNESYSTEM_HPP
#define PHYSICSENGINE_SWEEPANDPRUNESYSTEM_HPP

#include "System.hpp"

namespace PhysicsEngine
{

    class SweepAndPruneSystem : public System
    {
    public:
        explicit SweepAndPruneSystem(World &world) : System(world) {};

        void RegisterSystem(flecs::world &ecs) override;
    };

} // PhysicsSystem

#endif //PHYSICSENGINE_SWEEPANDPRUNESYSTEM_HPP
