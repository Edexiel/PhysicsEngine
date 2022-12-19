#ifndef PHYSICSENGINE_WORLD_HPP
#define PHYSICSENGINE_WORLD_HPP


#include <vector>
#include "raylib.h"
#include "Object/Object.hpp"
#include "Time/Timer.hpp"

struct CollisionPair
{
    CollisionPair(Object &a, Object &b) : a(a), b(b) {}
    Object &a, &b;
};

class System;

class World
{
private:
    Timer _timer{};
    Vector2 gravity{0, -9.81};
    Vector2 &screenSize;

    std::vector<CollisionPair> _pairsToCheck;
    std::vector<CollisionPair> _collidingPairs;
    std::vector<System *> _systems;
    std::vector<Object> _objects;
    void GetCollidingPairsToCheck(std::vector<CollisionPair> &pairsToCheck);
    void AABBCollisionCheck(std::vector<CollisionPair> &pairsToCheck);
    static bool AABBCollide(const Rectangle &a, const Rectangle &b);
    static Vector2 TripleProduct(const Vector2 &a, const Vector2 &b, const Vector2 &c);


    void BroadPhase();
    void NarrowPhase();

    bool gjk(Object &a, Object &ObjectB);

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
