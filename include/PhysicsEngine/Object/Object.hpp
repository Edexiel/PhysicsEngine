#ifndef PHYSICSENGINE_OBJECT_HPP
#define PHYSICSENGINE_OBJECT_HPP

#include <vector>
#include "raylib.h"

class Object
{

private:
    std::vector<Vector2> _points{};
    std::vector<Vector2> _transformedPoints{};

    Rectangle _boundingBox{};
    Rectangle _aabb{};
    float _rotation; //radian
    Vector2 _position;
    Vector2 _velocity;
    Color _color;

    void GenerateBoundingBox();

public:

    Object() = delete;
    explicit Object(const Vector2 &position, float rotation = 0.f);

    void addPoints(std::vector<Vector2> &&points);


    // Getter Setters
    const Vector2 &GetPosition() const;
    void SetPosition(const Vector2 &position);

    float GetRotation() const;
    void SetRotation(float rotation);
    Color GetColor() const;
    void SetColor(const Color &color);

    const Rectangle &GetAABB();
    std::vector<Vector2> &getTransformedPoints();


    // Movement
    void Rotate(float rotations);//degres
    void Move(const Vector2 &move);

    //Physic
    bool isPointInsideAABB(const Vector2 &point) const;
    bool isPointInside(const Vector2 &point) const;
    Vector2 &GetFurthestPoint(Vector2 direction);

    // Debug
    bool collide = false;
    bool isSelected = false;

    // Static functions
    static Vector2 GetSupport(Object &v1, Object &v2, Vector2 direction);
    static Object GetTriangle(float base, float height);
//    static Object GetRandomPoly(const RandomPolyParams &);


};


#endif //PHYSICSENGINE_OBJECT_HPP
