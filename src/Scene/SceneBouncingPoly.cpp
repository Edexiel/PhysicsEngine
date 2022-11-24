#include "Scene/SceneBouncingPoly.hpp"

#include "raylib.h"
#include "raymath.h"
#include "Scene/World.hpp"
#include "Object/Object.hpp"

SceneBouncingPoly::SceneBouncingPoly(World &world, int polycount) : SceneBase(world), _polycount(polycount) {}


void SceneBouncingPoly::Create()
{
    SceneBase::Create();

    TraceLog(LOG_INFO, "Creating scene bouncingPoly");

    float height = _world.GetScreenSize().y;
    float width = _world.GetScreenSize().x;

    RandomPolyParams params{};
    params.minRadius = 20.0f;
    params.maxRadius = 50.0f;
    params.minBounds = Vector2{.x=0, .y= 0};
    params.maxBounds = Vector2{.x=width, .y= height};
    params.minPoints = 3;
    params.maxPoints = 8;
    params.minSpeed = 1.0f;
    params.maxSpeed = 3.0f;

    for (int i = 0; i < _polycount; ++i)
    {
        _world.AddObject(Object::AddRandomPoly(params));
    }
}
