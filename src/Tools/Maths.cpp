#include "Tools/Maths.hpp"
#include "raymath.h"

Vector2 Maths::TripleProduct(const Vector2 &a, const Vector2 &b, const Vector2 &c)
{
    float z = a.x * b.y - a.y * b.x;
    return {-c.y * z, c.x * z};
}

std::vector<Vector2> Maths::MinkowskiSum(const std::vector<Vector2> &a, const std::vector<Vector2> &b)
{
    std::vector<Vector2> result{a.size() * b.size()};

    for (const auto point_a: a)
        for (const auto point_b: b)
            result.emplace_back(Vector2Add(point_a, point_b));


    return result;
}

std::vector<Vector2> Maths::MinkowskiDiff(const std::vector<Vector2> &a, const std::vector<Vector2> &b)
{
    std::vector<Vector2> result{a.size() * b.size()};

    for (const auto point_a: a)
        for (const auto point_b: b)
            result.emplace_back(Vector2Subtract(point_a, point_b));


    return result;
}
