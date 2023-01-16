#ifndef PHYSICSENGINE_INPUTSYSTEM_HPP
#define PHYSICSENGINE_INPUTSYSTEM_HPP


#include "System/System.hpp"

namespace PhysicsEngine
{

    class InputSystem : public System
    {
        flecs::system _select;
        flecs::system _unselect;
        flecs::system _move;

    public:
        explicit InputSystem(flecs::world &ecs);
        void Run() override;


    };
}

#endif //PHYSICSENGINE_INPUTSYSTEM_HPP
