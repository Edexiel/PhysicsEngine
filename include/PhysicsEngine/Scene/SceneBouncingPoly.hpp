#ifndef PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP
#define PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP


#include "Scene.hpp"
#include "Object/Object.hpp"
#include "Components/Shape.hpp"

namespace PhysicsEngine
{
    class SceneBouncingPoly : public Scene
    {
    private:
        unsigned int _polycount;
        Shape::RandomPolyParams _polyParams;
    public:
        explicit SceneBouncingPoly(World &world, int polycount, const Shape::RandomPolyParams &polyParams);
        void Create() override;
    };
}

#endif //PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP
