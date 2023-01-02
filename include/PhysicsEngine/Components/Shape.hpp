#ifndef PHYSICSENGINE_SHAPE_HPP
#define PHYSICSENGINE_SHAPE_HPP

#include <vector>
#include "raylib.h"


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
            std::vector<Vector2> points{};
        };

        struct TransformedPoints
        {
            std::vector<Vector2> points{};
        };

        struct VertexColor
        {
            Color color;
        };

        static void GetRandomPoly(const RandomPolyParams &params, Vector2 &position, Vector2 &velocity, float &rotation,
                                  std::vector<Vector2> &points);
        static void GetTriangle(float base, float height, std::vector<Vector2> &points);
        static bool PointInsideShape(const std::vector<Vector2> &transformedPoints, Vector2 point);
        static Vector2 GetFurthestPoint(std::vector<Vector2> &transformedPoints, Vector2 direction);
        static Vector2 GetSupport(std::vector<Vector2> &tp1, std::vector<Vector2> &tp2, Vector2 direction);


    };

}
#endif //PHYSICSENGINE_SHAPE_HPP
