#include <vector>
#include "Components/Transform.hpp"
#include "raymath.h"

void PhysicsEngine::Transform::Rotation::Rotate(float amount)
{
    rotation += amount * DEG2RAD;
    rotation = fmod(rotation, PI * 2) - PI;
}

void PhysicsEngine::Transform::Position::Move(const Vector2 &move)
{
    position = Vector2Add(position, move);
//  todo
//    _aabb.x = _boundingBox.x + _position.x;
//    _aabb.y = _boundingBox.y + _position.y;
}
