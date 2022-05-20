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
        ballXrand = distribution(generator);
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


    float paddleLeftTop = paddleLeftHeight;
    float paddleLeftBot = paddleLeftHeight + 86;

    float paddleRightTop = paddleRightHeight;
    float paddleRightBot = paddleRightHeight + 86;

    int leftScore = 0;
    int rightScore = 0;

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        if (IsKeyDown(KEY_W))
        {
            if (paddleLeftTop > 0)
                paddleLeftHeight -= 5;
        }
        if (IsKeyDown(KEY_S))
        {
            if (paddleLeftBot < screenHeight)
                paddleLeftHeight += 5;
        }
           

        if (IsKeyDown(KEY_UP))
        {
            if (paddleRightTop > 0)
                paddleRightHeight -= 5;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            if (paddleRightBot < screenHeight)
                paddleRightHeight += 5;
        }

        if (ballX <= -20)
        {
            ballX = screenWidth / 2;
            ballY = screenHeight / 2;
            ballXrand = distribution(generator);
            ballYrand = distribution(generator);
            while (ballXrand == 0)
            {
                ballXrand = distribution(generator);
            }
            while (ballYrand == 0)
            {
                ballYrand = distribution(generator);
            }
            ballXChange = 5 * ballXrand;
            ballYChange = 5 * ballYrand;
            rightScore++;
        }
        if (ballX >= screenWidth + 20)
        {
            ballX = screenWidth / 2;
            ballY = screenHeight / 2;
            ballXrand = distribution(generator);
            ballYrand = distribution(generator);
            while (ballXrand == 0)
            {
                ballXrand = distribution(generator);
            }
            while (ballYrand == 0)
            {
                ballYrand = distribution(generator);
            }
            ballXChange = 5 * ballXrand;
            ballYChange = 5 * ballYrand;
            leftScore++;
        }

        if (leftScore == 11 || rightScore == 11)
        {
            leftScore = 0;
            rightScore = 0;
        }

        paddleLeftTop = paddleLeftHeight;
        paddleLeftBot = paddleLeftHeight + 86;

        paddleRightTop = paddleRightHeight;
        paddleRightBot = paddleRightHeight + 86;

        if (ballXChange < 2.5 && ballXChange >= 0)
            ballXChange = 2.5;
        if (ballXChange > -2.5 && ballXChange < 0)
            ballXChange = -2.5;
        if (ballYChange < 2.5 && ballYChange >= 0)
            ballYChange = 2.5;
        if (ballYChange > -2.5 && ballYChange < 0)
            ballYChange = -2.5;

        if (ballY < screenHeight - 10)
        {
            directionChange = false; 
        }
        else if (ballY > 10)
        {
            directionChange = false;
        }

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

        if (ballY >= paddleLeftTop - 10 && ballY <= paddleLeftBot + 10 && ballX <= 25 && ballX >= 5 && ballXChange < 0)
            ballXChange = ballXChange * -1;
        if (ballY >= paddleRightTop - 10 && ballY <= paddleRightBot + 10 && ballX >= screenWidth - 20 && ballX <= screenWidth - 5 && ballXChange > 0)
            ballXChange = ballXChange * -1;

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


        /*if (leftScore == 0)
        {
            DrawRectangle(screenWidth / 2 - 30, 20, 10, 70, WHITE);
            DrawRectangle(screenWidth / 2 - 70, 20, 10, 70, WHITE);
            DrawRectangle(screenWidth / 2 - 70, 20, 50, 10, WHITE);
            DrawRectangle(screenWidth / 2 - 70, 80, 50, 10, WHITE);
        }
        else if (leftScore == 1)
        {
            DrawRectangle(screenWidth / 2 - 30, 20, 10, 70, WHITE);
        }
        if (leftScore == 8)
        {

            
        }*/

        if (leftScore == 0 || leftScore == 2 || leftScore == 3 || leftScore == 5 || leftScore == 6 || leftScore == 7 || leftScore == 8 || leftScore == 9 || leftScore == 10)
            DrawRectangle(screenWidth / 2 - 70, 20, 50, 10, WHITE); //TOP
        if (leftScore == 0 || leftScore == 4 || leftScore == 5 || leftScore == 6 || leftScore == 8 || leftScore == 9 || leftScore == 10)
            DrawRectangle(screenWidth / 2 - 70, 20, 10, 35, WHITE); // TOP Left
        if (leftScore == 0 || leftScore == 1 || leftScore == 2 || leftScore == 3 || leftScore == 4 || leftScore == 7 || leftScore == 8 || leftScore == 9 || leftScore == 10 || leftScore == 11)
            DrawRectangle(screenWidth / 2 - 30, 20, 10, 35, WHITE); // TOP Right
        if (leftScore == 2 || leftScore == 3 || leftScore == 4 || leftScore == 5 || leftScore == 6 || leftScore == 8 || leftScore == 9)
            DrawRectangle(screenWidth / 2 - 70, 50, 50, 10, WHITE); // MID
        if (leftScore == 0 || leftScore == 2 || leftScore == 6 || leftScore == 8 || leftScore == 10)
            DrawRectangle(screenWidth / 2 - 70, 50, 10, 35, WHITE); // Bottom Left
        if (leftScore == 0 || leftScore == 1 || leftScore == 3 || leftScore == 4 || leftScore == 5 || leftScore == 6 || leftScore == 7 || leftScore == 8 || leftScore == 9 || leftScore == 10 || leftScore == 11)
            DrawRectangle(screenWidth / 2 - 30, 55, 10, 35, WHITE); // Bottom Right
        if (leftScore == 0 || leftScore == 2 || leftScore == 3 || leftScore == 5 || leftScore == 6 || leftScore == 8 || leftScore == 9 || leftScore == 10)
            DrawRectangle(screenWidth / 2 - 70, 80, 50, 10, WHITE); // Bottom
        if (leftScore == 10)
        {
            DrawRectangle(screenWidth / 2 - 90, 20, 10, 35, WHITE); // TOP Right
            DrawRectangle(screenWidth / 2 - 90, 55, 10, 35, WHITE); // Bottom Right
        }
        if (leftScore >= 11)
        {
            DrawRectangle(screenWidth / 2 - 70, 20, 10, 35, WHITE); // TOP Left
            DrawRectangle(screenWidth / 2 - 70, 55, 10, 35, WHITE); // Bottom Left
        }

        if (rightScore == 0 || rightScore == 2 || rightScore == 3 || rightScore == 5 || rightScore == 6 || rightScore == 7 || rightScore == 8 || rightScore == 9)
            DrawRectangle(screenWidth / 2 + 20, 20, 50, 10, WHITE); //TOP
        if (rightScore == 0 || rightScore == 1 || rightScore == 4 || rightScore == 5 || rightScore == 6 || rightScore == 8 || rightScore == 9 || rightScore == 10)
            DrawRectangle(screenWidth / 2 + 20, 20, 10, 35, WHITE); // TOP Left
        if (rightScore == 0 || rightScore == 2 || rightScore == 3 || rightScore == 4 || rightScore == 7 || rightScore == 8 || rightScore == 9)
            DrawRectangle(screenWidth / 2 + 60, 20, 10, 35, WHITE); // TOP Right
        if (rightScore == 2 || rightScore == 3 || rightScore == 4 || rightScore == 5 || rightScore == 6 || rightScore == 8 || rightScore == 9)
            DrawRectangle(screenWidth / 2 + 20, 50, 50, 10, WHITE); // MID
        if (rightScore == 0 || rightScore == 1 || rightScore == 2 || rightScore == 6 || rightScore == 8 || rightScore == 10)
            DrawRectangle(screenWidth / 2 + 20, 55, 10, 35, WHITE); // Bottom Left
        if (rightScore == 0 || rightScore == 3 || rightScore == 4 || rightScore == 5 || rightScore == 6 || rightScore == 7 || rightScore == 8 || rightScore == 9)
            DrawRectangle(screenWidth / 2 + 60, 55, 10, 35, WHITE); // Bottom Right
        if (rightScore == 0 || rightScore == 2 || rightScore == 3 || rightScore == 5 || rightScore == 6 || rightScore == 8 || rightScore == 9)
            DrawRectangle(screenWidth / 2 + 20, 80, 50, 10, WHITE); // Bottom
        if (rightScore == 10)
        {
            DrawRectangle(screenWidth / 2 + 40, 20, 50, 10, WHITE); //TOP
            DrawRectangle(screenWidth / 2 + 40, 20, 10, 35, WHITE); // TOP Left
            DrawRectangle(screenWidth / 2 + 80, 20, 10, 35, WHITE); // TOP Right
            DrawRectangle(screenWidth / 2 + 40, 50, 10, 35, WHITE); // Bottom Left
            DrawRectangle(screenWidth / 2 + 80, 55, 10, 35, WHITE); // Bottom Right
            DrawRectangle(screenWidth / 2 + 40, 80, 50, 10, WHITE); // Bottom
        }
        if (rightScore >= 11)
        {
            DrawRectangle(screenWidth / 2 + 20, 20, 10, 35, WHITE); // TOP Left
            DrawRectangle(screenWidth / 2 + 20, 55, 10, 35, WHITE); // Bottom Left

            DrawRectangle(screenWidth / 2 + 60, 20, 10, 35, WHITE); // TOP Right
            DrawRectangle(screenWidth / 2 + 60, 55, 10, 35, WHITE); // Bottom Right
        }
            


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

