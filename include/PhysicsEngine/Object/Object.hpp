#ifndef PHYSICSENGINE_OBJECT_HPP
#define PHYSICSENGINE_OBJECT_HPP

#include <vector>
#include "raylib.h"

struct RandomPolyParams
{
    int minPoints, maxPoints;
    float minRadius, maxRadius;
    Vector2 minBounds, maxBounds;
    float minSpeed, maxSpeed;
};

class Object
{

private:
    std::vector<Vector2> _points{};
    std::vector<Vector2> _transformedPoints{};

    Rectangle _boundingBox{};
    void generateBoundingBox();
    float _rotation; //radian


public:

    Object() = delete;
    explicit Object(const Vector2 &position, float rotation = 0.f);
    Vector2 position;
    Vector2 speed;
    Color color = BLACK;

    bool isPointInside(const Vector2 &point) const;
    std::vector<Vector2> &getTransformedPoints();
    Rectangle getAABB();
    void Rotate(float rotations);//degres

//    static Object GetTriangle(float base, float height);
//    static Object GetRectangle(float width, float height);
//    static Object GetSquare(float size);
//    static Object GetSymetricPolygon(float radius, int sides);
    static Object AddRandomPoly(const RandomPolyParams &);


};


#endif //PHYSICSENGINE_OBJECT_HPP
