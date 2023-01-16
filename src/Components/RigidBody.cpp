#include "Components/RigidBody.hpp"
//
bool PhysicsEngine::RigidBody::PointInsideAABB(const Rectangle & aabb,const Vector2& p)
{
    return (p.x >= aabb.x && p.x <= aabb.x + aabb.width) && (p.y >= aabb.y && p.y <= p.y + aabb.height);
}
bool PhysicsEngine::RigidBody::compare(const Rectangle &a,const Rectangle &b)
{
    return (a.x < b.x);
}
