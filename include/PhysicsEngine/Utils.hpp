#ifndef PHYSICSENGINE_UTILS_HPP
#define PHYSICSENGINE_UTILS_HPP


#include <stdlib.h>

class Utils
{
public:
    template<typename T>
    static T Random(T from, T to);

};


template<typename T>
inline T Utils::Random(T from, T to)
{
    return from + (to - from) * (((float )rand()) / ((float )RAND_MAX));
}


#endif //PHYSICSENGINE_UTILS_HPP
