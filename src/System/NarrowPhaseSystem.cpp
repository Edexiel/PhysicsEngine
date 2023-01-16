#include "System/NarrowPhaseSystem.hpp"


#include "Components/RigidBody.hpp"
#include "flecs.h"
#include "Tools/Maths.hpp"
#include "Components/Transform.hpp"


PhysicsEngine::NarrowPhaseSystem::NarrowPhaseSystem(flecs::world &ecs) : System(ecs)
{

//    bool PhysicsEngine::World::gjk(Object &ObjectA, Object &ObjectB)
//    {
//
//        int index = 0;
//        Vector2 simplex[3]{};
//        Vector2 direction, ab, ao, ac, acperp, abperp;
//
//        //First point simplex[0] ==> a
//        simplex[0] = Object::GetSupport(ObjectA, ObjectB, {1.f, 0.f});
//        //First direction
//        direction = Vector2Scale(simplex[0], -1.f);
//
//        while (true)
//        {
//            index++;
//            //second point
//            simplex[index] = Object::GetSupport(ObjectA, ObjectB, direction);
//            //no collision
//            if (Vector2DotProduct(simplex[index], direction) <= 0)
//                return false;
//
//            if (index == 1) //Line
//            {
//                //second direction
//                ab = Vector2Subtract(simplex[1], simplex[0]);
//                ao = Vector2Scale(simplex[0], -1.f);
//
//                if (Vector2DotProduct(direction, ao) > 0)
//                {
//                    direction = Maths::TripleProduct(ab, ao, ab);
//                } else
//                {
//                    direction = ao;
//                    index--;
//                }
//                continue;
//            }
////        index == 2 //triangle
//
//            ab = Vector2Subtract(simplex[1], simplex[0]); //todo we already have it
//            ac = Vector2Subtract(simplex[2], simplex[0]);
//
//            acperp = Maths::TripleProduct(ab, ac, ac);
//
//            if (Vector2DotProduct(direction, ao) >= 0)
//            {
//                direction = acperp;
//            } else
//            {
//                abperp = Maths::TripleProduct(ac, ab, ab);
//
//                if (Vector2DotProduct(abperp, ao) < 0)
//                    return true; //collision
//
//                simplex[0] = simplex[1];
//                direction = abperp;
//            }
//            simplex[1] = simplex[2];
//            index--;
//        }
//
//        return false;
//    }
}
void PhysicsEngine::NarrowPhaseSystem::Run()
{
    System::Run();
}
