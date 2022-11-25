#ifndef PHYSICSENGINE_WORLD_HPP
#define PHYSICSENGINE_WORLD_HPP


#include <vector>
#include "raylib.h"
#include "Object/Object.hpp"
#include "Time/Timer.hpp"
#include <tuple>

class System;

class World
{
private:


    Timer _timer{};
    Vector2 gravity{0, -9.81};
    Vector2 &screenSize;

    std::vector<std::tuple<Object &, Object &>> _pairsToCheck{};
    std::vector<System *> _systems;
    std::vector<Object> _objects;
    void GetCollidingPairsToCheck(std::vector<std::tuple<Object &, Object &>> &pairsToCheck);
    bool CheckCollisionAABB(const Rectangle& a, const Rectangle&b) const;


    void broadphase();


public:

    explicit World(Vector2 &screenSize);


    void AddObject(Object &&);
    void Clear();
    void Update(float deltaTime, bool debug);
    void Draw(bool debug);

    const Vector2 &GetGravity() const;
    const Vector2 &GetScreenSize() const;

    const std::vector<Object> &GetObjects() const;


};


#endif //PHYSICSENGINE_WORLD_HPP
