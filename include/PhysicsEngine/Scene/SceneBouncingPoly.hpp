#ifndef PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP
#define PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP


#include "SceneBase.hpp"

class SceneBouncingPoly : public SceneBase
{
private:
    unsigned int _polycount;
public:
    explicit SceneBouncingPoly(World &world, int polycount);
    void Create() override;
};


#endif //PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP
