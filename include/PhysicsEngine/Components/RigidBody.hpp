#ifndef PHYSICSENGINE_RIGIDBODY_HPP
#define PHYSICSENGINE_RIGIDBODY_HPP

#include <vector>
#include "raylib.h"


namespace PhysicsEngine
{
    class RigidBody
    {

    public:
        struct Velocity
        {
            Vector2 velocity;
        };

        struct AABB
        {
            Rectangle aabb;
            bool PointInsideAABB(Vector2 point) const;

            bool operator()(Rectangle &a, Rectangle &b) const;

        };

    };
}

#endif //PHYSICSENGINE_RIGIDBODY_HPP
