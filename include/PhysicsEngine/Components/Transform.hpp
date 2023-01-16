#ifndef PHYSICSENGINE_TRANSFORM_HPP
#define PHYSICSENGINE_TRANSFORM_HPP

#include "raymath.h"


namespace PhysicsEngine
{
    struct Target
    {

    };
    class Transform
    {
    public:
        struct Position
        {
            Vector2 position;
        };

        struct Rotation
        {
            float rotation;
        };

        static float Rotate( float rotation,float amount);
        static Vector2 Move(const Vector2& position,const Vector2 &move);

    };
}

#endif //PHYSICSENGINE_TRANSFORM_HPP
