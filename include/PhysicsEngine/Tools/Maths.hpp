//
// Created by guillaume on 20/12/22.
//

#ifndef PHYSICSENGINE_MATHS_HPP
#define PHYSICSENGINE_MATHS_HPP

#include "raylib.h"
#include <vector>

class Maths
{
public :
    static Vector2 TripleProduct(const Vector2 &a, const Vector2 &b, const Vector2 &c);

    static std::vector<Vector2> MinkowskiSum(const std::vector<Vector2> &a, const std::vector<Vector2> &b);
    static std::vector<Vector2> MinkowskiDiff(const std::vector<Vector2> &a, const std::vector<Vector2> &b);

    static bool AABBCollide(const Rectangle &a, const Rectangle &b);
    static bool AABBCollideX(const Rectangle &a, const Rectangle &b);
    static bool AABBCollideY(const Rectangle &a, const Rectangle &b);

};

// Simplification of AABB collide for SAP in Y
inline bool Maths::AABBCollideY(const Rectangle &a, const Rectangle &b)
{
    return a.y + a.height >= b.y && b.y + b.height >= a.y;
}

// Simplification of AABB collide for SAP in X
inline bool Maths::AABBCollideX(const Rectangle &a, const Rectangle &b)
{
    return a.x + a.width >= b.x && b.x + b.width >= a.x;

}

inline bool Maths::AABBCollide(const Rectangle &a, const Rectangle &b)
{
    return AABBCollideX(a, b) && AABBCollideY(a, b);
}


#endif //PHYSICSENGINE_MATHS_HPP
