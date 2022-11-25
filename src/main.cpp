#include "raylib.h"
#include "Scene/SceneManager.hpp"
#include "Scene/World.hpp"
#include "fmt/core.h"
#include "Scene/SceneBouncingPoly.hpp"
#include "Object/Object.hpp"

#define RAYMATH_STATIC_INLINE

int main()
{
    bool debug = true;
    bool fpsLock = false;

    Vector2 screenSize{.x=1280, .y=720};

    InitWindow((int) screenSize.x, (int) screenSize.y, "Physics engine");

    SetTargetFPS(0);

    World world{screenSize};

    RandomPolyParams params
            {
                    .minPoints = 3,
                    .maxPoints = 8,
                    .minRadius = 10.0f,
                    .maxRadius = 35.0f,
                    .minBounds = Vector2{.x=50, .y= 50},
                    .maxBounds = Vector2{.x=screenSize.x - 50, .y=screenSize.y - 50},
                    .minSpeed = 1.0f,
                    .maxSpeed = 3.0f
            };


    SceneManager sceneManager{world};
    sceneManager.AddScene<SceneBouncingPoly>(world, 50, params);


    sceneManager.LoadScene(0);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        if (IsKeyPressed(KEY_F1))
            sceneManager.Reload();

        if (IsKeyPressed(KEY_F2))
            sceneManager.LoadScene(
                    sceneManager.GetCurrentSceneIndex() > 0 ? sceneManager.GetCurrentSceneIndex() - 1 : 0);

        if (IsKeyPressed(KEY_F3))
            sceneManager.LoadScene(sceneManager.GetCurrentSceneIndex() + 1);

        if (IsKeyPressed(KEY_F4))         //Do debug stuff
            debug = !debug;

        if (IsKeyPressed(KEY_F5))
        {
            fpsLock = !fpsLock;
            SetTargetFPS(fpsLock ? 60 : 0);
        }

        // Update
        world.Update(GetFrameTime(), debug);


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        world.Draw(debug);

        DrawText(fmt::format("F1: Reset scene, F2: prev scene, F3: next scene, cur scene: {}, F4: debug, F5: lock FPS",
                             sceneManager.GetCurrentSceneIndex()).c_str(), 5, 0, 20, LIME);
        DrawFPS((int) screenSize.x - (int) (screenSize.x / 10), 0);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();

    return 0;
}
