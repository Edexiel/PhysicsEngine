#ifndef PHYSICSENGINE_SHAPE_HPP
#define PHYSICSENGINE_SHAPE_HPP

#include <vector>
#include "raylib.h"
#include "flecs.h"


namespace PhysicsEngine
{
    class Shape
    {
    public:
        struct RandomPolyParams
        {
            int minPoints, maxPoints;
            float minRadius, maxRadius;
            Vector2 minBounds, maxBounds;
            float minSpeed, maxSpeed;
        };

        struct Points
        {
            flecs::vector<Vector2> points{};
        };

        struct TransformedPoints
        {
            flecs::vector<Vector2> points{};
        };

        struct VertexColor
        {
            Color color;
        };

        static flecs::vector<Vector2>
        GetRandomPoly(const RandomPolyParams &params, Vector2 &position, Vector2 &velocity, float &rotation);
        static flecs::vector<Vector2> GetTriangle(float base, float height);
        static bool PointInsideShape(const std::vector<Vector2> &transformedPoints, Vector2 point);
        static Vector2 GetFurthestPoint(std::vector<Vector2> &transformedPoints, Vector2 direction);
        static Vector2 GetSupport(std::vector<Vector2> &tp1, std::vector<Vector2> &tp2, Vector2 direction);


    };

}
#endif //PHYSICSENGINE_SHAPE_HPP
