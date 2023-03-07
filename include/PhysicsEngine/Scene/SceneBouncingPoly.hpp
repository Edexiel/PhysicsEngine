#ifndef PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP
#define PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP


#include "Scene.hpp"
#include "Components/Shape.hpp"

namespace PhysicsEngine
{
    class SceneBouncingPoly : public Scene
    {
    private:

        unsigned int _polycount;
        Shape::RandomPolyParams _polyParams;
    public:
        explicit SceneBouncingPoly(World& world,int polycount, const Shape::RandomPolyParams &polyParams);
        virtual ~SceneBouncingPoly();


        void Create(flecs::world& ecs,const World& world) override;
        void Update(flecs::world& ecs,const World& world) override;
    };
}

#endif //PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP
