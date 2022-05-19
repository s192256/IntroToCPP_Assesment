/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "DataFile.h"

#include <iostream>

int recordIndexInt = 1;
int theRecordCount;

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    DataFile data;
    int currentRecordIdx = 0;

    // Load Function accepts the recordIndexInt to determine which record to view
    data.Load("npc_data.dat", recordIndexInt);

    // Gets the amount of Records in the data file
    theRecordCount = data.GetRecordCount();

    DataFile::Record* currentRecord = data.GetRecord(currentRecordIdx);
    Texture2D recordTexture = LoadTextureFromImage(currentRecord->image);


    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        if (IsKeyPressed(KEY_LEFT))
        {
            currentRecordIdx--;
            // Sets recordIndexInt to the Record Count if the users tries to make the RecordIndexInt 
            // less than record 1 to allow user to cycle through the record constantly 
            recordIndexInt--;
            if (recordIndexInt <= 0)
                recordIndexInt = theRecordCount;
           
                
               

            data.Load("npc_data.dat", recordIndexInt);

            if (currentRecordIdx < 0)
            {
                currentRecordIdx = 0;
            }
            currentRecord = data.GetRecord(currentRecordIdx);
            recordTexture = LoadTextureFromImage(currentRecord->image);
        }

        if (IsKeyPressed(KEY_RIGHT))
        {
            currentRecordIdx++;

            // Sets recordIndexInt to the 1 if the users tries to make the RecordIndexInt 
            // more than record the amount of records to allow user to cycle through the record constantly 
            recordIndexInt++;
            if (recordIndexInt == theRecordCount + 1)
                recordIndexInt = 1;
               

            data.Load("npc_data.dat", recordIndexInt);

            // prevents currentRecordIdx from going higher than the amount of Records in the data
            if (currentRecordIdx >= data.GetRecordCount() - 1)
            {
                currentRecordIdx = data.GetRecordCount() - 1;
            }
            currentRecord = data.GetRecord(currentRecordIdx);
            recordTexture = LoadTextureFromImage(currentRecord->image);
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(recordTexture, 300, 50, WHITE);

        DrawText("NAME", 10, 50, 20, LIGHTGRAY);
        DrawText(currentRecord->name.c_str(), 10, 80, 20, LIGHTGRAY);

        DrawText("AGE", 10, 120, 20, LIGHTGRAY);
        DrawText(to_string(currentRecord->age).c_str(), 10, 150, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}