#include "raylib.h"
#include <iostream>



int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "PONG");

    SetTargetFPS(60);

    float paddleLeftHeight = screenHeight / 2 - 43;

    float paddleRightHeight = screenHeight / 2 - 43;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
       
      
        if (IsKeyDown(KEY_W))
            paddleLeftHeight -= 2.5;

        if (IsKeyDown(KEY_S))
            paddleLeftHeight += 2.5;

        if (IsKeyDown(KEY_UP))
            paddleRightHeight -= 2.5;

        if (IsKeyDown(KEY_DOWN))
            paddleRightHeight += 2.5;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);


        DrawText("|", screenWidth / 2, 7.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 37.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 67.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 97.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 127.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 157.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 187.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 217.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 247.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 277.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 307.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 337.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 367.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 397.5, 20, WHITE);
        DrawText("|", screenWidth / 2, 427.5, 20, WHITE);

        DrawRectangle(10, paddleLeftHeight, 6, 86, WHITE);
        DrawRectangle(screenWidth - 10, paddleRightHeight, 6, 86, WHITE);

        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}