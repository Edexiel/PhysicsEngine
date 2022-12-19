#include "Scene/World.hpp"
#include "Object/Object.hpp"
#include <algorithm>
#include "raymath.h"
#include "Utils.hpp"

struct
{
    inline bool operator()(Object &a, Object &b) const
    {
        return (a.getAABB().x < b.getAABB().x);
    }
} AABBComp;

Vector2 World::TripleProduct(const Vector2 &a, const Vector2 &b, const Vector2 &c)
{
    float z = a.x * b.y - a.y * b.x;
    return {-c.y * z, c.x * z};
}

World::World(Vector2 &screenSize) : screenSize(screenSize) {}

inline bool World::AABBCollide(const Rectangle &a, const Rectangle &b)
{
//    bool collisionX = a.x + a.width >= b.x && b.x + b.width >= a.x;
    return a.y + a.height >= b.y && b.y + b.height >= a.y;

//    return collisionX && collisionY;

}

//Sweep and prune
void World::GetCollidingPairsToCheck(std::vector<CollisionPair> &pairsToCheck)
{
    pairsToCheck.clear();
    std::sort(_objects.begin(), _objects.end(), AABBComp);

    for (int i = 0; i < _objects.size(); ++i)
    {
        const Rectangle &rec = _objects[i].getAABB();

        for (int j = i + 1; j < _objects.size(); ++j)
        {
            const Rectangle &nextRec = _objects[j].getAABB();

            if (nextRec.x > (rec.x + rec.width))
            {
                _objects[i].collide = false;
                _objects[j].collide = false;

                break;
            }
//            _objects[i].color = PURPLE;
//            _objects[j].color = PURPLE;
            pairsToCheck.emplace_back(_objects[i], _objects[j]);
        }
    }
}
void World::AABBCollisionCheck(std::vector<CollisionPair> &pairsToCheck)
{
    _collidingPairs.clear();

    for (const CollisionPair &pair: _pairsToCheck)
    {
        if (AABBCollide(pair.a.getAABB(), pair.b.getAABB()))
        {
            pair.a.collide = true;
            pair.b.collide = true;
            _collidingPairs.emplace_back(pair);
        }
    }
}


void World::BroadPhase()
{
    GetCollidingPairsToCheck(_pairsToCheck);
    AABBCollisionCheck(_pairsToCheck);
}

bool World::gjk(Object &ObjectA, Object &ObjectB)
{
    int index = 0;
    Vector2 simplex[3]{};
    Vector2 direction, ab, ao, ac, acperp, abperp;

    //First point simplex[0] ==> a
    simplex[0] = Object::GetSupport(ObjectA, ObjectB, {1.f, 0.f});
    //First direction
    direction = Vector2Scale(simplex[0], -1.f);

    while (true)
    {
        index++;
        //second point
        simplex[index] = Object::GetSupport(ObjectA, ObjectB, direction);
        //no collision
        if (Vector2DotProduct(simplex[index], direction) <= 0)
            return false;

        if (index == 1) //Line
        {
            //second direction
            ab = Vector2Subtract(simplex[1], simplex[0]);
            ao = Vector2Scale(simplex[0], -1.f);

            if (Vector2DotProduct(direction, ao) > 0)
            {
                direction = TripleProduct(ab, ao, ab);
            } else
            {
                direction = ao;
                index--;
            }
            continue;
        }
//        index == 2 //triangle

        //a => simplex[0]
        //b => simplex[1]
        //c => simplex[2] => current index

        ab = Vector2Subtract(simplex[1], simplex[0]); //todo we already have it
        ac = Vector2Subtract(simplex[2], simplex[0]);

        acperp = TripleProduct(ab, ac, ac);

        if (Vector2DotProduct(direction, ao) >= 0)
        {
            direction = acperp;
        } else
        {
            abperp = TripleProduct(ac, ab, ab);
            if (Vector2DotProduct(abperp, ao) < 0)
                return true; //collision

            simplex[0] = simplex[1];
            direction = abperp;
        }
        simplex[1] = simplex[2];
        index--;
    }

    return false;
}

void World::NarrowPhase()
{
    for (const auto &pair: _collidingPairs)
    {
        if (gjk(pair.a, pair.b))
        {
            pair.a.color = PURPLE;
            pair.b.color = PURPLE;
        }
    }
}

void World::Update(float deltaTime, bool debug)
{
    _timer.Start();
    BroadPhase();
    _timer.Stop();

    if (debug)
    {
        std::basic_string<char> message = _timer.GetStringDuration("Broad phase :");
        DrawText(message.c_str(), 5, (int) screenSize.y - 40, 20, LIME);
        TraceLog(LOG_DEBUG, message.c_str());
    }

    _timer.Start();
    NarrowPhase();
    _timer.Stop();

    if (debug)
    {
        std::basic_string<char> message = _timer.GetStringDuration("Narrow phase :");
        DrawText(message.c_str(), 5, (int) screenSize.y - 20, 20, LIME);
        TraceLog(LOG_DEBUG, message.c_str());
    }

}

void World::Draw(bool debug)
{
    for (auto &object: _objects)
    {
        std::vector<Vector2> &points = object.getTransformedPoints();
        DrawLineStrip(points.data(), (int) points.size(), object.color);
        DrawLineV(points[0], points[points.size() - 1], object.color);

        if (debug)
        {
            const Rectangle &temp = object.getAABB();
            const Color color = object.collide ? PURPLE : LIME;

            DrawLine(temp.x, temp.y, temp.x + temp.width, temp.y, color); //top
            DrawLine(temp.x, temp.y + temp.height, temp.x + temp.width, temp.y + temp.height, color); //top
            DrawLine(temp.x, temp.y, temp.x, temp.y + temp.height, color); //left
            DrawLine(temp.x + temp.width, temp.y, temp.x + temp.width, temp.y + temp.height, color); //right

        }
    }
}
const Vector2 &World::GetGravity() const
{
    return gravity;
}
const Vector2 &World::GetScreenSize() const
{
    return screenSize;
}
void World::AddObject(Object &&object)
{
    _objects.emplace_back(object);
}

void World::Clear()
{
    _objects.clear();
}

const std::vector<Object> &World::GetObjects() const
{
    return _objects;
}

