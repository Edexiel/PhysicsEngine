
#ifndef PHYSICSENGINE_SYSTEM_HPP
#define PHYSICSENGINE_SYSTEM_HPP

#include <vector>

class Object;

class System
{
protected:
    System() = default;
    virtual void Update(float deltaTime, const std::vector<Object> &) const = 0;
};


#endif //PHYSICSENGINE_SYSTEM_HPP
