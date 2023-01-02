#ifndef PHYSICSENGINE_TRANSFORM_HPP
#define PHYSICSENGINE_TRANSFORM_HPP

#include "raymath.h"


namespace PhysicsEngine
{
    class Transform
    {
    public:
        struct Position
        {
            Vector2 position;
            void Move(const Vector2 &move);
        };

        struct Rotation
        {
            float rotation;
            void Rotate(float amount);
        };

    };
}

#endif //PHYSICSENGINE_TRANSFORM_HPP
