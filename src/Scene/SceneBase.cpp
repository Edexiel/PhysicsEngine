#include "Scene/SceneBase.hpp"
#include "Scene/World.hpp"

SceneBase::SceneBase(World &world) : _world(world) {}

void SceneBase::Create()
{
    TraceLog(LOG_INFO,"Creating base scene");
}

