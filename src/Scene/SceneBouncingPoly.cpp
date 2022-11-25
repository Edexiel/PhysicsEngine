#include "Scene/SceneBouncingPoly.hpp"

#include "raylib.h"
#include "raymath.h"
#include "Scene/World.hpp"

SceneBouncingPoly::SceneBouncingPoly(World &world, int polycount, const RandomPolyParams &polyParams) :
        SceneBase(world), _polycount(polycount), _polyParams(polyParams) {}


void SceneBouncingPoly::Create()
{
    SceneBase::Create();

    TraceLog(LOG_INFO, "Creating scene bouncingPoly");

    for (int i = 0; i < _polycount; ++i)
    {
        _world.AddObject(Object::AddRandomPoly(_polyParams));
    }
}
