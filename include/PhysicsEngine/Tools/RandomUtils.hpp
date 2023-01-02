#ifndef PHYSICSENGINE_RANDOMUTILS_HPP
#define PHYSICSENGINE_RANDOMUTILS_HPP


#include <stdlib.h>
#include <vector>
#include "raymath.h"

class RandomUtils
{
public:
    template<typename T>
    static T RandomRange(T from, T to);
};

template<typename T>
inline T RandomUtils::RandomRange(T from, T to)
{
    return from + (to - from) * (((float) rand()) / ((float) RAND_MAX));
}


#endif //PHYSICSENGINE_RANDOMUTILS_HPP
