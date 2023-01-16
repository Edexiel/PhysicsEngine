#ifndef PHYSICSENGINE_RIGIDBODY_HPP
#define PHYSICSENGINE_RIGIDBODY_HPP

#include <vector>
#include "raylib.h"
#include "flecs.h"

namespace PhysicsEngine
{
    class RigidBody
    {
    public:
        struct BroadTag
        {
            flecs::entity second;
        };

        struct NarrowTag
        {
        };
        struct Collide
        {

        };

        struct Velocity
        {
            Vector2 velocity;
        };

        struct AABB
        {
            Rectangle aabb;

        };

//        struct AABBColor
//        {
//            Color color;
//        };

        static bool compare(const Rectangle &a, const Rectangle &b);
        static bool PointInsideAABB(const Rectangle &aabb, const Vector2 &point);


    };
}

#endif //PHYSICSENGINE_RIGIDBODY_HPP
