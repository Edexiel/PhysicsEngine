#ifndef PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP
#define PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP


#include "SceneBase.hpp"
#include "Object/Object.hpp"

class SceneBouncingPoly : public SceneBase
{
private:
    unsigned int _polycount;
    RandomPolyParams _polyParams;
public:
    explicit SceneBouncingPoly(World &world, int polycount,const RandomPolyParams& polyParams);
    void Create() override;
};


#endif //PHYSICSENGINE_SCENEBOUNCINGPOLY_HPP
