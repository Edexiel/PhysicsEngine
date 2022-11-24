#ifndef PHYSICSENGINE_WORLD_HPP
#define PHYSICSENGINE_WORLD_HPP


#include <vector>
#include "raylib.h"
#include "Object/Object.hpp"

class System;

class World
{
private:
    Vector2 &screenSize;

    std::vector<System *> _systems;
    std::vector<Object> _objects;

    Vector2 gravity{0, -9.81};

public:

    explicit World(Vector2 &screenSize);


    void AddObject(Object &&);
    void Clear();
    void Update(float deltaTime);
    void Draw(bool debug);

    const Vector2 &GetGravity() const;
    const Vector2 & GetScreenSize() const;

    const std::vector<Object> &GetObjects() const;


};


#endif //PHYSICSENGINE_WORLD_HPP
