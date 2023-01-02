#include "World.hpp"
#include "Object/Object.hpp"
#include <algorithm>
#include "raymath.h"
#include "Tools/Maths.hpp"
#include "System/System.hpp"
#include "flecs.h"

struct
{
    inline bool operator()(Object &a, Object &b) const
    {
        return (a.GetAABB().x < b.GetAABB().x);
    }
} AABBComp;

PhysicsEngine::World::World(Vector2 &screenSize, bool &debug) : screenSize(screenSize), _debug(debug)
{
    _ecs = new flecs::world;
}

//Sweep and prune
void PhysicsEngine::World::GetCollidingPairsToCheck(std::vector<CollisionPair> &pairsToCheck)
{
    pairsToCheck.clear();
    std::sort(_objects.begin(), _objects.end(), AABBComp);

    for (int i = 0; i < _objects.size(); ++i)
    {
        const Rectangle &rec = _objects[i].GetAABB();

        for (int j = i + 1; j < _objects.size(); ++j)
        {
            const Rectangle &nextRec = _objects[j].GetAABB();

            if (nextRec.x > (rec.x + rec.width))
            {
                _objects[i].collide = false;
                _objects[j].collide = false;

                break;
            }
            pairsToCheck.emplace_back(_objects[i], _objects[j]);
        }
    }
}
void PhysicsEngine::World::AABBCollisionCheck(std::vector<CollisionPair> &pairsToCheck)
{
    _collidingPairs.clear();

    for (const CollisionPair &pair: _pairsToCheck)
    {
        if (Maths::AABBCollideY(pair.a.GetAABB(), pair.b.GetAABB()))
        {
            pair.a.collide = pair.b.collide = true;
            _collidingPairs.emplace_back(pair);
        }
    }
}


void PhysicsEngine::World::BroadPhase()
{
    GetCollidingPairsToCheck(_pairsToCheck);
    AABBCollisionCheck(_pairsToCheck);
}

//bool PhysicsEngine::World::gjk(Object &ObjectA, Object &ObjectB)
//{
//
//    int index = 0;
//    Vector2 simplex[3]{};
//    Vector2 direction, ab, ao, ac, acperp, abperp;
//
//    //First point simplex[0] ==> a
//    simplex[0] = Object::GetSupport(ObjectA, ObjectB, {1.f, 0.f});
//    //First direction
//    direction = Vector2Scale(simplex[0], -1.f);
//
//    while (true)
//    {
//        index++;
//        //second point
//        simplex[index] = Object::GetSupport(ObjectA, ObjectB, direction);
//        //no collision
//        if (Vector2DotProduct(simplex[index], direction) <= 0)
//            return false;
//
//        if (index == 1) //Line
//        {
//            //second direction
//            ab = Vector2Subtract(simplex[1], simplex[0]);
//            ao = Vector2Scale(simplex[0], -1.f);
//
//            if (Vector2DotProduct(direction, ao) > 0)
//            {
//                direction = Maths::TripleProduct(ab, ao, ab);
//            } else
//            {
//                direction = ao;
//                index--;
//            }
//            continue;
//        }
////        index == 2 //triangle
//
//        ab = Vector2Subtract(simplex[1], simplex[0]); //todo we already have it
//        ac = Vector2Subtract(simplex[2], simplex[0]);
//
//        acperp = Maths::TripleProduct(ab, ac, ac);
//
//        if (Vector2DotProduct(direction, ao) >= 0)
//        {
//            direction = acperp;
//        } else
//        {
//            abperp = Maths::TripleProduct(ac, ab, ab);
//
//            if (Vector2DotProduct(abperp, ao) < 0)
//                return true; //collision
//
//            simplex[0] = simplex[1];
//            direction = abperp;
//        }
//        simplex[1] = simplex[2];
//        index--;
//    }
//
//    return false;
//}

void PhysicsEngine::World::NarrowPhase()
{
    for (const auto &pair: _collidingPairs)
    {
        if (gjk(pair.a, pair.b))
        {
            pair.a.SetColor(RED);
            pair.b.SetColor(RED);
        }
    }
}

//void PhysicsEngine::World::Update(float deltaTime, bool debug)
//{
//    _timer.Start();
//    BroadPhase();
//    _timer.Stop();
//
//    if (debug)
//    {
//        std::basic_string<char> message = _timer.GetStringDuration("Broad phase :");
//        DrawText(message.c_str(), 5, (int) screenSize.y - 40, 20, LIME);
//    }
//
//    _timer.Start();
//    NarrowPhase();
//    _timer.Stop();
//
//    if (debug)
//    {
//        std::basic_string<char> message = _timer.GetStringDuration("Narrow phase :");
//        DrawText(message.c_str(), 5, (int) screenSize.y - 20, 20, LIME);
//    }
//    _timer.Start();
//
//    for (const auto &system: _systems)
//    {
//        system->Update(deltaTime, _objects);
//    }
//    _timer.Stop();
//    if (debug)
//    {
//        std::basic_string<char> message = _timer.GetStringDuration("Systems :");
//        DrawText(message.c_str(), 5, (int) screenSize.y - 60, 20, LIME);
//    }
//
//}


//Object &PhysicsEngine::World::AddObject(Object &&object)
//{
//    return _objects.emplace_back(object);
//}

void PhysicsEngine::World::Clear()
{
    for (System *s: _systems)
    {
        delete s;
    }

    delete _ecs;
    _ecs = new flecs::world;
}

const std::vector<Object> &PhysicsEngine::World::GetObjects() const
{
    return _objects;
}
