#include <raylib.h>
#include <stdlib.h>
#include <string.h>

/***
 * 2048 0 0 0
 * 0 0 0 0
 * 0 0 0 0
 * 0 0 0 0
 */

int main(int argc, char* argv[])
{
    InitWindow(800, 800, "2049 by faithgvn");

    int scoreboard = 0;
    int piecesx = GetRandomValue(0, 3);
    int piecesy = GetRandomValue(0, 3);
    int gameMatrix[4][4] = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    };
    int emptyCell = 16;

    while (!WindowShouldClose()) {
        /* Read Keyboard Inputs */
        bool isDownPressed = IsKeyPressed(KEY_DOWN);
        bool isUpPressed = IsKeyPressed(KEY_UP);
        bool isRightPressed = IsKeyPressed(KEY_RIGHT);
        bool isLeftPressed = IsKeyPressed(KEY_LEFT);
        bool isAnyKeyPressed = false;

        /* Do logic */

        if (isDownPressed) {
            isAnyKeyPressed = true;
        }
        if (isUpPressed) {
            isAnyKeyPressed = true;
        }
        if (isRightPressed) {
            isAnyKeyPressed = true;
        }
        if (isLeftPressed) {
            isAnyKeyPressed = true;
        }

        if (isAnyKeyPressed && emptyCell > 0 || emptyCell == 16) {
            while (gameMatrix[piecesy][piecesx] != 0) {
                piecesx = GetRandomValue(0, 3);
                piecesy = GetRandomValue(0, 3);
            }
            gameMatrix[piecesy][piecesx] = 2;
            emptyCell = emptyCell - 1;
        }

        /* Draw everthing */

        BeginDrawing();
        ClearBackground(WHITE);

        /* Draw board background */
        DrawRectangle(100, 100, 600, 600, GRAY);

        /* Draw pieces */
        int x = 0;
        while (x < 4) {
            int y = 0;
            while (y < 4) {
                if (gameMatrix[y][x] != 0) {
                    char appear[7] = "";

                    sprintf(appear, "%d", gameMatrix[y][x]);
                    DrawRectangle(100 + (x * 150), 100 + (y * 150), 150, 150, RED);
                    DrawText(appear, 100 + (x * 150) + 20, 100 + (y * 150) + 55, 40, WHITE);
                }
                y = y + 1;
            }
            x = x + 1;
        }

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
