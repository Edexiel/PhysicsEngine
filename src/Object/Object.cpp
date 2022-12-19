#include "Object/Object.hpp"
#include "raylib.h"
#include "raymath.h"
#include "float.h"
#include "Utils.hpp"

Object::Object(const Vector2 &position, float rotation) : _position(position), _rotation(DEG2RAD * rotation)
{
//    generateBoundingBox();
////    _aabb = {_boundingBox};
//    _aabb.x = _boundingBox.x + _position.x;
//    _aabb.y = _boundingBox.y + _position.y;
//    _aabb.width = _boundingBox.width;
//    _aabb.height = _boundingBox.height;

}

bool Object::isPointInside(const Vector2 &point) const
{
    return false;
}

std::vector<Vector2> &Object::getTransformedPoints()
{
    for (int i = 0; i < _points.size(); ++i)
    {
        _transformedPoints[i] = Vector2Add(_position, Vector2Rotate(_points[i], _rotation));
    }

    return _transformedPoints;
}

void Object::generateBoundingBox()
{
    _boundingBox.x = FLT_MAX, _boundingBox.y = FLT_MAX;
    float maxX{FLT_MIN}, maxY{FLT_MIN};

    for (const auto &point: _points)
    {
        Vector2 rotated{Vector2Rotate(point, _rotation)};

        if (rotated.x < _boundingBox.x)
            _boundingBox.x = rotated.x;
        if (rotated.x > maxX)
            maxX = rotated.x;

        if (rotated.y < _boundingBox.y)
            _boundingBox.y = rotated.y;
        if (rotated.y > maxY)
            maxY = rotated.y;
    }

    _boundingBox.width = maxX - _boundingBox.x;
    _boundingBox.height = maxY - _boundingBox.y;
}


const Rectangle &Object::getAABB()
{
//    generateBoundingBox();
    _aabb = {_boundingBox};
    _aabb.x = _boundingBox.x + _position.x;
    _aabb.y = _boundingBox.y + _position.y;
    _aabb.width = _boundingBox.width;
    _aabb.height = _boundingBox.height;
    return _aabb;
}
void Object::Rotate(float rotations)
{
    _rotation += rotations * DEG2RAD;
    _rotation = fmod(_rotation, PI * 2) - PI; //todo test this
    generateBoundingBox(); // todo not gonna work, points arents really rotated so no new bounding box
}
void Object::Move(const Vector2 &move)
{
//    _dirtyPosAABB = true; //object was moved, need to recalculate AABB position
    _position = Vector2Add(_position, move);

    _aabb.x = _boundingBox.x + _position.x;
    _aabb.y = _boundingBox.y + _position.y;
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
    std::vector<Vector2> points{};
    Vector2 pos
            {
                    .x=Utils::Random(params.minBounds.x, params.maxBounds.x),
                    .y=Utils::Random(params.minBounds.y, params.maxBounds.y)
            };

    float rotation = Utils::Random(-180.0f, 180.0f);

    int pointsCount = Utils::Random(params.minPoints, params.maxPoints);

    Object obj{pos, rotation};

    float radius = Utils::Random(params.minRadius, params.maxRadius);

    float dAngle = 360.0f / (float) pointsCount;
    for (int i = 0; i < pointsCount; ++i)
    {
        float angle = (float) i * dAngle + Utils::Random(-dAngle / 3.0f, dAngle / 3.0f);
        float dist = radius;

        points.emplace_back(Vector2Scale(Vector2{.x=cosf(DEG2RAD * angle), .y=sinf(DEG2RAD * angle)}, dist));
    }

    obj.addPoints(std::move(points));

//    obj.speed = Utils::Random(params.minSpeed, params.maxSpeed);

    return obj;
}
void Object::addPoints(std::vector<Vector2> &&points)
{
    _points = std::move(points);
    _transformedPoints.resize(_points.size(), _points[0]);
    generateBoundingBox();
}
Vector2 &Object::GetFurthestPoint(Vector2 direction) //todo opti
{
    float maxDistance = -FLT_MAX;
    Vector2 &bestPoint = _transformedPoints[0];

    for (const Vector2 &vertex: _transformedPoints)
    {
        float distance = Vector2DotProduct(vertex, direction);

        if (distance > maxDistance)
        {
            maxDistance = distance;
            bestPoint = vertex;
        }
    }
    return bestPoint;
}
Vector2 Object::GetSupport(Object &o1, Object &o2, Vector2 direction)
{
    return Vector2Subtract(o1.GetFurthestPoint(direction), o2.GetFurthestPoint(Vector2Scale(direction, -1)));
}
inline const Vector2 &Object::GetPosition() const
{
    return _position;
}
