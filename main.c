#include <raylib.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    InitWindow(800, 800, "2049 by faithgvn");

    int scoreboard = 0;
    int piecesx = 1;
    int piecesy = 1;
    while (!WindowShouldClose()) {
        /* Read Keyboard Inputs */
        bool isDownPressed = IsKeyPressed(KEY_DOWN);
        bool isUpPressed = IsKeyPressed(KEY_UP);
        bool isRightPressed = IsKeyPressed(KEY_RIGHT);
        bool isLeftPressed = IsKeyPressed(KEY_LEFT);

        /* Do logic */

        if (isDownPressed) {
            piecesy = piecesy + 1;
        }
        if (isUpPressed) {
            piecesy = piecesy - 1;
        }
        if (isRightPressed) {
            piecesx = piecesx + 1;
        }
        if (isLeftPressed) {
            piecesx = piecesx - 1;
        }

        /* Draw everthing */

        BeginDrawing();
        ClearBackground(WHITE);

        /* Draw board background */
        DrawRectangle(100, 100, 600, 600, GRAY);

        /* Draw pieces */
        DrawRectangle(piecesx * 150 - 50, piecesy * 150 - 50, 150, 150, RED);
        DrawText("2048", piecesx * 150 + 20 - 50, piecesy * 150 + 55 - 50, 40, WHITE);

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
