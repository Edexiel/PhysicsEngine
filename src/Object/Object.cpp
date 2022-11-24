#include "Object/Object.hpp"
#include "raylib.h"
#include "raymath.h"
#include "float.h"
#include "Utils.hpp"

Object::Object(const Vector2 &position, float rotation) : position(position), _rotation(DEG2RAD * rotation)
{
    generateBoundingBox();
}

bool Object::isPointInside(const Vector2 &point) const
{
    return false;
}

std::vector<Vector2> &Object::getTransformedPoints()
{
    _transformedPoints.clear();
    _transformedPoints.reserve(_points.size());

    for (const auto &point: _points)
    {
        _transformedPoints.push_back(Vector2Add(position, Vector2Rotate(point, _rotation)));
    }
    return _transformedPoints;
}
void Object::generateBoundingBox()
{
    float minX{FLT_MAX}, minY{FLT_MAX}, maxX{FLT_MIN}, maxY{FLT_MIN};

    for (const auto &point: _points)
    {
        Vector2 rotated{Vector2Rotate(point, _rotation)};

        if (rotated.x < minX)
            minX = rotated.x;
        if (rotated.x > maxX)
            maxX = rotated.x;

        if (rotated.y < minY)
            minY = rotated.y;
        if (rotated.y > maxY)
            maxY = rotated.y;
    }

    _boundingBox.x = minX;
    _boundingBox.y = minY;
    _boundingBox.width = maxX - minX;
    _boundingBox.height = maxY - minY;
}
Rectangle Object::getAABB()
{
    Rectangle AABB{_boundingBox};
    AABB.x += position.x;
    AABB.y += position.y;
    return AABB;
}
void Object::Rotate(float rotations)
{
    _rotation += rotations * DEG2RAD;
    _rotation = fmod(_rotation, PI * 2) - PI; //todo test this
    generateBoundingBox();
}
//Object Object::GetTriangle(float base, float height)
//{
//    return Object(Vector2());
//}
//Object Object::GetRectangle(float width, float height)
//{
//    return Object(Vector2());
//}
//Object Object::GetSquare(float size)
//{
//    return Object(Vector2());
//}
//Object Object::GetSymetricPolygon(float radius, int sides)
//{
//    return Object(Vector2());
//}
Object Object::AddRandomPoly(const RandomPolyParams &params)
{
    Vector2 position
            {
                    .x=Utils::Random(params.minBounds.x, params.maxBounds.x),
                    .y=Utils::Random(params.minBounds.y, params.maxBounds.y)
            };

    float rotation = Utils::Random(-180.0f, 180.0f);

    int pointsCount = Utils::Random(params.minPoints, params.maxPoints);

    Object obj{position, rotation};

    float radius = Utils::Random(params.minRadius, params.maxRadius);

    float dAngle = 360.0f / (float) pointsCount;
    for (int i = 0; i < pointsCount; ++i)
    {
        float angle = (float) i * dAngle + Utils::Random(-dAngle / 3.0f, dAngle / 3.0f);
        float dist = radius;

        Vector2 point = Vector2Scale(Vector2{.x=cosf(DEG2RAD * angle), .y=sinf(DEG2RAD * angle)}, dist);
        obj._points.push_back(point);
    }
//    obj.speed = Utils::Random(params.minSpeed, params.maxSpeed);

    obj.generateBoundingBox();
    return obj;
}
