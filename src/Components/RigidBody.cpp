#include "Components/RigidBody.hpp"

bool PhysicsEngine::RigidBody::AABB::PointInsideAABB(Vector2 p) const
{
    return (p.x >= aabb.x && p.x <= aabb.x + aabb.width) && (p.y >= aabb.y && p.y <= p.y + aabb.height);
}
bool PhysicsEngine::RigidBody::AABB::operator()(Rectangle &a, Rectangle &b) const
{
    return (a.x < b.x);
}
