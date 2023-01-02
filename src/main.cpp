#include "raylib.h"
#include "Scene/SceneManager.hpp"
#include "World.hpp"
#include "fmt/core.h"
#include "Scene/SceneBouncingPoly.hpp"
#include "Scene/SceneDebug.hpp"
#include "Object/Object.hpp"

#define RAYMATH_STATIC_INLINE

int main()
{
    bool debug = true;
    bool fpsLock = false;

    Vector2 screenSize{.x=1280, .y=720};

    InitWindow((int) screenSize.x, (int) screenSize.y, "Physics engine");

    SetTargetFPS(0);

    PhysicsEngine::World world{screenSize, debug};

    PhysicsEngine::Shape::RandomPolyParams params
            {
                    .minPoints = 3,
                    .maxPoints = 7,
                    .minRadius = 10.0f,
                    .maxRadius = 20.0f,
                    .minBounds = Vector2{.x=50, .y= 50},
                    .maxBounds = Vector2{.x=screenSize.x - 50, .y=screenSize.y - 50},
                    .minSpeed = 1.0f,
                    .maxSpeed = 3.0f
            };

    PhysicsEngine::SceneManager sceneManager{world};
    sceneManager.AddScene<PhysicsEngine::SceneDebug>(world);
    sceneManager.AddScene<PhysicsEngine::SceneBouncingPoly>(world, 200, params);

    sceneManager.LoadScene(0);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        if (IsKeyPressed(KEY_F1))
            sceneManager.Reload();

        if (IsKeyPressed(KEY_F2))
            sceneManager.LoadScene(sceneManager.GetSceneIndex() > 0 ? sceneManager.GetSceneIndex() - 1 : 0);

        if (IsKeyPressed(KEY_F3))
            sceneManager.LoadScene(sceneManager.GetSceneIndex() + 1);

        if (IsKeyPressed(KEY_F4))         //Do debug stuff
            debug = !debug;

        if (IsKeyPressed(KEY_F5))
        {
            fpsLock = !fpsLock;
            SetTargetFPS(fpsLock ? 60 : 0);
        }

        // Update
//        world.Update(GetFrameTime(), debug);


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText(fmt::format("F1: Reset scene, F2: Prev. scene, F3: Next scene,F4: Debug, F5: Lock FPS").c_str(), 5, 0,
                 20, LIME);
        DrawText(fmt::format("Current scene: {}", sceneManager.GetSceneIndex() + 1).c_str(), 5, 25, 20, LIME);

        DrawFPS((int) screenSize.x - (int) (screenSize.x / 10), 0);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();

    return 0;
}
