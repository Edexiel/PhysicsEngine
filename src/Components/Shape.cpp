#include <float.h>
#include "Components/Shape.hpp"
#include "Tools/RandomUtils.hpp"

void PhysicsEngine::Shape::GetTriangle(float base, float height, std::vector<Vector2> &points)
{
    points.push_back({-base * 0.5f, height * 0.5f});
    points.push_back({base * 0.5f, height * 0.5f});
    points.push_back({0.0f, -height * 0.5f});
}
void PhysicsEngine::Shape::GetRandomPoly(const PhysicsEngine::Shape::RandomPolyParams &params, Vector2 &position,
                                         Vector2 &velocity, float &rotation, std::vector<Vector2> &points)
{
    position =
            {
                    .x=RandomUtils::RandomRange(params.minBounds.x, params.maxBounds.x),
                    .y=RandomUtils::RandomRange(params.minBounds.y, params.maxBounds.y)
            };

    velocity =
            {
                    .x=RandomUtils::RandomRange(params.minSpeed, params.maxSpeed),
                    .y=RandomUtils::RandomRange(params.minSpeed, params.maxSpeed),
            };

    rotation = RandomUtils::RandomRange(-180.0f, 180.0f);

    const int pointsCount = RandomUtils::RandomRange(params.minPoints, params.maxPoints);
    const float radius = RandomUtils::RandomRange(params.minRadius, params.maxRadius);
    const float dAngle = 360.0f / (float) pointsCount;

    for (int i = 0; i < pointsCount; ++i)
    {
        float angle = (float) i * dAngle + RandomUtils::RandomRange(-dAngle / 3.0f, dAngle / 3.0f);
        float dist = radius;

        points.emplace_back(Vector2Scale(Vector2{.x=cosf(DEG2RAD * angle), .y=sinf(DEG2RAD * angle)}, dist));
    }

}
bool PhysicsEngine::Shape::PointInsideShape(const std::vector<Vector2> &transformedPoints, Vector2 point)
{
    float maxDist = -FLT_MAX;

    for (int i = 0; i < transformedPoints.size(); i++)
    {
        Vector2 a = transformedPoints[i];
        Vector2 b = transformedPoints[(i + 1) % transformedPoints.size()];
        Vector2 nDir = Vector2Normalize(Vector2Subtract(b, a));

        Vector2 temp = Vector2Subtract(point, a);
        float dist = Vector2DotProduct(temp, nDir);

        maxDist = dist > maxDist ? dist : maxDist;
    }

    return maxDist <= 0.f;
}
Vector2 PhysicsEngine::Shape::GetFurthestPoint(std::vector<Vector2> &transformedPoints, Vector2 direction)
{
    float maxDistance = -FLT_MAX;
    Vector2 &bestPoint = transformedPoints[0];

    for (const Vector2 &vertex: transformedPoints)
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
Vector2 PhysicsEngine::Shape::GetSupport(std::vector<Vector2> &tp1, std::vector<Vector2> &tp2, Vector2 direction)
{
    return Vector2Subtract(GetFurthestPoint(tp1, direction), GetFurthestPoint(tp2, Vector2Scale(direction, -1)));
}
