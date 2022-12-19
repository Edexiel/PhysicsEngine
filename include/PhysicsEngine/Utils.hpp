#ifndef PHYSICSENGINE_UTILS_HPP
#define PHYSICSENGINE_UTILS_HPP


#include <stdlib.h>
#include <vector>
#include "raymath.h"

class Utils
{
public:
    template<typename T>
    static T Random(T from, T to);

//    static std::vector<Vector2> MinkowskiSum(const std::vector<Vector2> &a, const std::vector<Vector2> &b);
//    static std::vector<Vector2> MinkowskiDiff(const std::vector<Vector2> &a, const std::vector<Vector2> &b);
};



//std::vector<Vector2> Utils::MinkowskiSum(const std::vector<Vector2> &a, const std::vector<Vector2> &b)
//{
//    std::vector<Vector2> result{a.size() * b.size()};
//
//    for (const auto point_a: a)
//        for (const auto point_b: b)
//            result.emplace_back(Vector2Add(point_a, point_b));
//
//
//    return result;
//}
//
//std::vector<Vector2> Utils::MinkowskiDiff(const std::vector<Vector2> &a, const std::vector<Vector2> &b)
//{
//    std::vector<Vector2> result{a.size() * b.size()};
//
//    for (const auto point_a: a)
//        for (const auto point_b: b)
//            result.emplace_back(Vector2Subtract(point_a, point_b));
//
//
//    return result;
//}


template<typename T>
inline T Utils::Random(T from, T to)
{
    return from + (to - from) * (((float) rand()) / ((float) RAND_MAX));
}


#endif //PHYSICSENGINE_UTILS_HPP
