#include <raylib.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    InitWindow(800, 800, "2049 by faithgvn");

    int scoreboard = 0;

    while (!WindowShouldClose()) {
        /* Read Keyboard Inputs */

        /* Do logic */

        /* Draw everthing */

        BeginDrawing();
        ClearBackground(WHITE);

        /* Draw board background */
        DrawRectangle(100, 100, 600, 600, GRAY);

        /* Draw pieces */
        DrawRectangle(100, 100, 150, 150, RED);
        DrawText("2048", 140, 155, 40, WHITE);

        /* Draw borders */
        DrawLine(250, 100, 250, 700, WHITE);
        DrawLine(400, 100, 400, 700, WHITE);
        DrawLine(550, 100, 550, 700, WHITE);
        DrawLine(100, 250, 700, 250, WHITE);
        DrawLine(100, 400, 700, 400, WHITE);
        DrawLine(100, 550, 700, 550, WHITE);

        /* memset(buffer, 0, 16);
        DrawText(itoa(scoreboard, buffer, 10), 10, 30, 20, BLACK); */

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
