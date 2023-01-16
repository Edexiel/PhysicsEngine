#ifndef PHYSICSENGINE_DRAWSYSTEM_HPP
#define PHYSICSENGINE_DRAWSYSTEM_HPP


#include "System.hpp"

namespace PhysicsEngine
{
    class DrawSystem : public System
    {
    private:
        const bool &_debug;
    public:
        explicit DrawSystem(flecs::world &ecs,bool& debug);
        void Run() override;

    };
}

#endif //PHYSICSENGINE_DRAWSYSTEM_HPP
