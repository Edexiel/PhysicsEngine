#include "Scene/World.hpp"
#include "Object/Object.hpp"
#include <algorithm>

struct
{
    bool operator()(Object &a, Object &b) const
    {
        return (a.getAABB().x < b.getAABB().x);
    }
} AABBComp;

World::World(Vector2 &screenSize) : screenSize(screenSize) {}

bool World::CheckCollisionAABB(const Rectangle &a, const Rectangle &b) const
{
    bool collisionX = a.x + a.width >= b.x && b.x + b.width >= a.x;
    bool collisionY = a.y + a.height >= b.y && b.y + b.height >= a.y;

    return collisionX && collisionY;

}
void World::GetCollidingPairsToCheck(std::vector<std::tuple<Object &, Object &>> &pairsToCheck)
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
            _objects[i].color = PURPLE;
            _objects[j].color = PURPLE;
            pairsToCheck.emplace_back(_objects[i], _objects[j]);
        }
    }
}


void World::broadphase()
{
    GetCollidingPairsToCheck(_pairsToCheck);

    for (auto &pairsToCheck: _pairsToCheck)
    {
        Object &a = std::get<0>(pairsToCheck);
        Object &b = std::get<1>(pairsToCheck);

        if (CheckCollisionAABB(a.getAABB(), b.getAABB()))
        {

            a.collide = true;
            b.collide = true;
        }

    }

}


void World::Update(float deltaTime, bool debug)
{
    _timer.Start();
    broadphase();
    _timer.Stop();

    if (debug)
    {
        std::basic_string<char> message = _timer.GetStringDuration("Broad phase :");
        DrawText(message.c_str(), 5, (int) screenSize.y - 40, 20, LIME);
        TraceLog(LOG_DEBUG, message.c_str());
    }

//    _timer.Start();
//    //narrowphase
//    _timer.Stop();
//
//    if (debug)
//    {
//        std::basic_string<char> message = _timer.GetStringDuration("Narrow phase :");
//        DrawText(message.c_str(), 5, (int) screenSize.y - 20, 20, LIME);
//        TraceLog(LOG_DEBUG, message.c_str());
//    }

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
            const Color color = object.collide ? RED : LIME;

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

