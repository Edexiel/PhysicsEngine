#include "Scene.hpp"
#include "raylib.h"
#include "System/TransformSystem.hpp"
#include "System/AABBGenerationSystem.hpp"

#ifndef PHYSICSENGINE_SCENEDEBUG_HPP
#define PHYSICSENGINE_SCENEDEBUG_HPP

namespace PhysicsEngine
{
    class SceneDebug : public Scene
    {
    public:
        explicit SceneDebug(World& world);
        virtual ~SceneDebug() = default;


        void Create(flecs::world &ecs,const World& world) override;
        void Update(const World& world) override;
    };
}

#endif //PHYSICSENGINE_SCENEDEBUG_HPP
