#include "Scene/World.hpp"
#include "Object/Object.hpp"

World::World(Vector2 &screenSize) : screenSize(screenSize) {}


void World::Update(float deltaTime)
{

}

void World::Draw(bool debug)
{
    for (auto &object: _objects)
    {
        std::vector<Vector2> &points = object.getTransformedPoints();
        DrawLineStrip(points.data(), (int) points.size(), object.color);
        DrawLineV(points[0],points[points.size()-1], object.color);

        if (debug)
            DrawRectangleLinesEx(object.getAABB(),1.f, LIME);
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

