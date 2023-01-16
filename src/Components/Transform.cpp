#include <vector>
#include "Components/Transform.hpp"
#include "raymath.h"

float PhysicsEngine::Transform::Rotate( float rotation,float amount)
{
    rotation += amount * DEG2RAD;
    rotation = fmod(rotation, PI * 2) - PI;

    return rotation;
}

Vector2 PhysicsEngine::Transform::Move(const Vector2& position,const Vector2 &move)
{
    return Vector2Add(position, move);
}
