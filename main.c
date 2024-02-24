#include <raylib.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    InitWindow(800, 800, "2049 by faithgvn");

    int scoreboard = 0;
    int piecesx = 100;
    int piecesy = 100;
    while (!WindowShouldClose()) {
        /* Read Keyboard Inputs */
        bool isDownPressed = IsKeyPressed(KEY_DOWN);
        bool isUpPressed = IsKeyPressed(KEY_UP);
        bool isRightPressed = IsKeyPressed(KEY_RIGHT);
        bool isLeftPressed = IsKeyPressed(KEY_LEFT);

        /* Do logic */

        if (isDownPressed) {
            piecesy = piecesy + 150;
        }
        if (isUpPressed) {
            piecesy = piecesy - 150;
        }
        if (isRightPressed) {
            piecesx = piecesx + 150;
        }
        if (isLeftPressed) {
            piecesx = piecesx - 150;
        }

        /* Draw everthing */

        BeginDrawing();
        ClearBackground(WHITE);

        /* Draw board background */
        DrawRectangle(100, 100, 600, 600, GRAY);

        /* Draw pieces */
        DrawRectangle(piecesx, piecesy, 150, 150, RED);
        DrawText("2048", piecesx + 20, piecesy + 55, 40, WHITE);

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
