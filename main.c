#include <raylib.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    InitWindow(800, 800, "2049 by faithgvn");

    while (!WindowShouldClose()) {
        /* Read Keyboard Inputs */

        /* Do logic */

        /* Draw everthing */

        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(100, 100, 600, 600, GRAY);
        DrawLine(250, 100, 250, 700, WHITE);
        DrawLine(400, 100, 400, 700, WHITE);
        DrawLine(550, 100, 550, 700, WHITE);
        DrawLine(100, 250, 700, 250, WHITE);
        DrawLine(100, 400, 700, 400, WHITE);
        DrawLine(100, 550, 700, 550, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
