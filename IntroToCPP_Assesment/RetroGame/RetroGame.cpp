#include "raylib.h"
#include <iostream>
#include <random>



int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "PONG");

    SetTargetFPS(60);

    float ballX = screenWidth / 2;
    float ballY = screenHeight / 2;

    std::random_device r;
    std::default_random_engine generator{ r() };
    std::uniform_real_distribution<float> distribution(-1.0, 1.0);
    float rand = distribution(generator);
    float rand2 = distribution(generator);


    float ballXrand = rand;
    float ballYrand = rand2;

    while (ballXrand == 0)
    {
        ballXrand = distribution(generator);;
    }
    while (ballYrand == 0)
    {
        ballYrand = distribution(generator);
    }

    float ballXChange = 5 * ballXrand;
    float ballYChange = 5 * ballYrand;

    bool directionChange = false;

    float paddleLeftHeight = screenHeight / 2 - 43;
    float paddleRightHeight = screenHeight / 2 - 43;

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_W))
            paddleLeftHeight -= 2.5;
        if (IsKeyDown(KEY_S))
            paddleLeftHeight += 2.5;

        if (IsKeyDown(KEY_UP))
            paddleRightHeight -= 2.5;

        if (IsKeyDown(KEY_DOWN))
            paddleRightHeight += 2.5;

        if (ballXChange < 2.5 && ballXChange >= 0)
            ballXChange = 2.5;
        if (ballXChange > -2.5 && ballXChange < 0)
            ballXChange = -2.5;
        if (ballYChange < 2.5 && ballYChange >= 0)
            ballYChange = 2.5;
        if (ballYChange > -2.5 && ballYChange < 0)
            ballYChange = -2.5;

        if (ballY > screenHeight - 10)
        {
            if (directionChange == false)
            {
                directionChange = true;
                ballYChange = ballYChange * -1;
            }
        }
        else if (ballY < 10)
        {
            if (directionChange == false)
            {
                directionChange = true;
                ballYChange = ballYChange * -1;
            }
        }

        ballX += (ballXChange);
        ballY += (ballYChange);


        // Draw
        // 
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);


        DrawText("|", screenWidth / 2 - 1, 7.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 37.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 67.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 97.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 127.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 157.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 187.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 217.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 247.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 277.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 307.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 337.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 367.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 397.5, 20, WHITE);
        DrawText("|", screenWidth / 2 - 1, 427.5, 20, WHITE);

        DrawCircle(ballX, ballY, 10, WHITE);
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

