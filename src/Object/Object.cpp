#include "Object/Object.hpp"
#include "raylib.h"
#include "raymath.h"
#include "float.h"
#include "Tools/RandomUtils.hpp"

Object::Object(const Vector2 &position, float rotation) : _position(position), _rotation(DEG2RAD * rotation),
                                                          _color(BLACK) {}

bool Object::isPointInsideAABB(const Vector2 &p) const
{
    return (p.x >= _aabb.x && p.x <= _aabb.x + _aabb.width) && (p.y >= _aabb.y && p.y <= p.y + _aabb.height);
}

std::vector<Vector2> &Object::getTransformedPoints()
{
    for (int i = 0; i < _points.size(); ++i)
    {
        _transformedPoints[i] = Vector2Add(_position, Vector2Rotate(_points[i], _rotation));
    }

    return _transformedPoints;
}

void Object::GenerateBoundingBox()
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


const Rectangle &Object::GetAABB()
{
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
    GenerateBoundingBox();
}

void Object::Move(const Vector2 &move)
{
    _position = Vector2Add(_position, move);

    _aabb.x = _boundingBox.x + _position.x;
    _aabb.y = _boundingBox.y + _position.y;
}

Object Object::GetTriangle(float base, float height)
{
    std::vector<Vector2> points{};

    Object obj{Vector2Zero(), 0.f};

    points.push_back({-base * 0.5f, height * 0.5f});
    points.push_back({base * 0.5f, height * 0.5f});
    points.push_back({0.0f, -height * 0.5f});

    obj.addPoints(std::move(points));
    return obj;
}

//Object Object::GetRandomPoly(const RandomPolyParams &params)
//{
//    std::vector<Vector2> points{};
//    Vector2 pos
//            {
//                    .x=RandomUtils::RandomRange(params.minBounds.x, params.maxBounds.x),
//                    .y=RandomUtils::RandomRange(params.minBounds.y, params.maxBounds.y)
//            };
//
//    float rotation = RandomUtils::RandomRange(-180.0f, 180.0f);
//
//    int pointsCount = RandomUtils::RandomRange(params.minPoints, params.maxPoints);
//
//    Object obj{pos, rotation};
//
//    float radius = RandomUtils::RandomRange(params.minRadius, params.maxRadius);
//
//    float dAngle = 360.0f / (float) pointsCount;
//    for (int i = 0; i < pointsCount; ++i)
//    {
//        float angle = (float) i * dAngle + RandomUtils::RandomRange(-dAngle / 3.0f, dAngle / 3.0f);
//        float dist = radius;
//
//        points.emplace_back(Vector2Scale(Vector2{.x=cosf(DEG2RAD * angle), .y=sinf(DEG2RAD * angle)}, dist));
//    }
//
//    obj.addPoints(std::move(points));
//
////    obj.speed = Utils::Random(params.minSpeed, params.maxSpeed);
//
//    return obj;
//}
void Object::addPoints(std::vector<Vector2> &&points)
{
    _points = std::move(points);
    _transformedPoints.resize(_points.size(), _points[0]);
    GenerateBoundingBox();
}
Vector2 &Object::GetFurthestPoint(Vector2 direction) //todo opti ?
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
void Object::SetPosition(const Vector2 &position)
{
    _position = position;
}
float Object::GetRotation() const
{
    return _rotation;
}
void Object::SetRotation(float rotation)
{
    _rotation = rotation;
}
Color Object::GetColor() const
{
    return _color;
}
void Object::SetColor(const Color &color)
{
    _color = color;
}
bool Object::isPointInside(const Vector2 &point) const
{
    float maxDist = -FLT_MAX;

    for (int i = 0; i < _transformedPoints.size(); i++)
    {
        Vector2 a = _transformedPoints[i];
        Vector2 b = _transformedPoints[(i + 1) % _transformedPoints.size()];
        Vector2 nDir = Vector2Normalize(Vector2Subtract(b, a));

        Vector2 temp = Vector2Subtract(point, a);
        float dist = Vector2DotProduct(temp, nDir);

        maxDist = dist > maxDist ? dist : maxDist;
    }

    return maxDist <= 0.f;
}
