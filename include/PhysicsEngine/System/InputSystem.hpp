#ifndef PHYSICSENGINE_INPUTSYSTEM_HPP
#define PHYSICSENGINE_INPUTSYSTEM_HPP


#include "System.hpp"

namespace PhysicsEngine
{

    class InputSystem : public System
    {
    public:
        explicit InputSystem(World &world) : System(world) {};

        void RegisterSystem(flecs::world &ecs) override;

        struct Target
        {
        };
    };
}

#endif //PHYSICSENGINE_INPUTSYSTEM_HPP
