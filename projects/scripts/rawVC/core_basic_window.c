/*****************************************************************************
*---|----1----|----2----|----3----|----4----|----5----|----6----|----7----|--*
*
* core_basic_windows.c 2021-09-30 adaptation
*
*   raylib [core] example - core_basic_window.c from raylib/projects/scripts/
*
*   Welcome to raylib!
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h
*   for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*   Touched up by orcmid on 2021-09-30 and confirmed with raylib 3.7.0
*
*****************************************************************************/

#pragma warning (disable:4820)
    // https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-4-c4820
    // as long as the raylib files are compiled to have the same paddings
    // there's no action required about these warnings concerning raylib.h

#include <raylib.h>

int main(void)
{
    // Initialization
    //------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight,
               "raylib [core] example - basic window");

    SetTargetFPS(60);
    //------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //--------------------------------------------------------------------
        // TODO: Update your variables here
        //--------------------------------------------------------------------

        // Draw
        //--------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!",
                     190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //--------------------------------------------------------------------
    }

    // De-Initialization
    //------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //------------------------------------------------------------------------

    return 0;
}
