#ifndef PHYSICSENGINE_WORLD_HPP
#define PHYSICSENGINE_WORLD_HPP


#include <vector>
#include "raylib.h"
#include "Time/Timer.hpp"

namespace flecs
{
    class world;
}

namespace PhysicsEngine
{
    struct Object{};
    struct CollisionPair
    {
        CollisionPair(Object &a, Object &b) : a(a), b(b) {}
        Object &a, &b;
        Vector2 point{};
        Vector2 normal{};
        float penetration{};
    };



    class World
    {
    private:

        std::vector<CollisionPair> _pairsToCheck;
        std::vector<CollisionPair> _collidingPairs;
        std::vector<class System *> _systems;
//        std::vector<Object> _objects;


//        void GetCollidingPairsToCheck(std::vector<CollisionPair> &pairsToCheck);
        void AABBCollisionCheck(std::vector<CollisionPair> &pairsToCheck);

        void BroadPhase();
        void NarrowPhase();

//        bool gjk(Object &a, Object &ObjectB);

        // Debug
        Timer _timer{};


    public:
        World(Vector2 &screenSize, bool &debug);

        void Init();
//        void Update(float deltaTime, bool debug);
        void Clear();


        template<class T, typename ... Types>
        void AddSystem(Types... t);

        const Vector2 gravity{0, -9.81};
        const Vector2 &screenSize;
        const bool &_debug;
        flecs::world *_ecs;


    };

    template<class T, typename... Types>
    void World::AddSystem(Types... t)
    {
        _systems.emplace_back(new T(*this, t...));
    }

}
#endif //PHYSICSENGINE_WORLD_HPP
