#include "Scene.hpp"

#ifndef PHYSICSENGINE_SCENEDEBUG_HPP
#define PHYSICSENGINE_SCENEDEBUG_HPP

namespace PhysicsEngine
{
    class SceneDebug : public Scene
    {
    public:
        explicit SceneDebug(World &world);
        void Create() override;

    };
}

#endif //PHYSICSENGINE_SCENEDEBUG_HPP
