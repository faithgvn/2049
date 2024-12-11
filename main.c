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
    int gameMatrix[4][4] = { 0 };
    bool isGameOver = false;

    while (!WindowShouldClose()) {
        /* Read Keyboard Inputs */
        bool isDownPressed = IsKeyPressed(KEY_DOWN);
        bool isUpPressed = IsKeyPressed(KEY_UP);
        bool isRightPressed = IsKeyPressed(KEY_RIGHT);
        bool isLeftPressed = IsKeyPressed(KEY_LEFT);
        bool isAnyKeyPressed = false;
        int moveCount = 0;
        int equalpairs = 0;
        /* Do logic */

        int emptyCell = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (gameMatrix[i][j] == 0) {
                    emptyCell++;
                }
            }
        }

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

        if (isGameOver == false) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    if (gameMatrix[i][j] == gameMatrix[i + 1][j]) {
                        equalpairs++;
                    }
                    if (equalpairs > 0) {
                        break;
                    }
                }
                if (equalpairs > 0) {
                    break;
                }
            }
        }

        if (isGameOver == false) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (gameMatrix[i][j] == gameMatrix[i][j + 1]) {
                        equalpairs++;
                    }
                    if (equalpairs > 0) {
                        break;
                    }
                }
                if (equalpairs > 0) {
                    break;
                }
            }
        }
        if (equalpairs == 0 && emptyCell == 0) {
            isGameOver = true;
        }

        /* Move all pieces to left */

        if (isLeftPressed) {
            int x = 1;
            while (x < 4) {
                int y = 0;
                while (y < 4) {
                    int tempX = x;
                    while (tempX != 0) {
                        if (gameMatrix[y][tempX] == 0) {
                            break;
                        }
                        if (gameMatrix[y][tempX] == gameMatrix[y][tempX - 1] && gameMatrix[y][tempX - 1]>0) {
                            gameMatrix[y][tempX] = -(gameMatrix[y][tempX] + gameMatrix[y][tempX - 1]);
                            gameMatrix[y][tempX -1] = 0;
                        }
                        if (gameMatrix[y][tempX - 1] == 0) {
                            gameMatrix[y][tempX - 1] = gameMatrix[y][tempX];
                            gameMatrix[y][tempX] = 0;
                            moveCount++;
                        }
                        tempX = tempX - 1;
                    }
                    y = y + 1;
                }
                x = x + 1;
            }
        }

        if (isRightPressed) {
            int x = 2;
            while (x >= 0) {
                int y = 0;
                while (y < 4) {
                    int tempX = x;
                    while (tempX != 3) {
                        if (gameMatrix[y][tempX] == 0) {
                            break;
                        }
                        if (gameMatrix[y][tempX] == gameMatrix[y][tempX + 1] && gameMatrix[y][tempX + 1]>0) {
                            gameMatrix[y][tempX] = -(gameMatrix[y][tempX] + gameMatrix[y][tempX + 1]);
                            gameMatrix[y][tempX + 1] = 0;
                        }
                        if (gameMatrix[y][tempX+1] == 0) {
                            gameMatrix[y][tempX + 1] = gameMatrix[y][tempX];
                            gameMatrix[y][tempX] = 0;
                            moveCount++;
                        }
                        tempX = tempX + 1;
                    }
                    y = y + 1;
                }
                x = x - 1;
            }
        }

        if (isDownPressed) {
            int y = 2;
            while (y >= 0) {
                int x = 0;
                while (x < 4) {
                    int tempY = y;
                    while (tempY != 3) {
                        if (gameMatrix[tempY][x] == 0) {
                            break;
                        }
                        if (gameMatrix[tempY][x] == gameMatrix[tempY + 1][x] && gameMatrix[tempY + 1][x]>0) {
                            gameMatrix[tempY][x] = -(gameMatrix[tempY][x] + gameMatrix[tempY + 1][x]);
                            gameMatrix[tempY + 1][x] = 0;
                        }
                        if (gameMatrix[tempY + 1][x] == 0) {
                            gameMatrix[tempY + 1][x] = gameMatrix[tempY][x];
                            gameMatrix[tempY][x] = 0;
                            moveCount++;
                        }
                        tempY = tempY + 1;
                    }
                    x = x + 1;
                }
                y = y - 1;
            }
        }

        if (isUpPressed) {
            int y = 1;
            while (y < 4) {
                int x = 0;
                while (x < 4) {
                    int tempY = y;
                    while (tempY != 0) {
                        if (gameMatrix[tempY][x] == 0) {
                            break;
                        }
                        if (gameMatrix[tempY][x] == gameMatrix[tempY - 1][x] && gameMatrix[tempY - 1][x]>0) {
                            gameMatrix[tempY][x] = -(gameMatrix[tempY][x] + gameMatrix[tempY - 1][x]);
                            gameMatrix[tempY - 1][x] = 0;
                        }
                        if (gameMatrix[tempY - 1][x] == 0) {
                            gameMatrix[tempY - 1][x] = gameMatrix[tempY][x];
                            gameMatrix[tempY][x] = 0;
                            moveCount++;
                        }
                        tempY = tempY - 1;
                    }
                    x = x + 1;
                }
                y = y + 1;
            }
        }

        for(int i=0;i<4;i++){
            for(int j = 0 ;j<4;j++){
                if(gameMatrix[i][j] < 0){
                    gameMatrix[i][j] = -gameMatrix[i][j];
                }
            }
        }

        if ((isAnyKeyPressed && moveCount > 0) || (isAnyKeyPressed && emptyCell == 16)) {
            moveCount = 0;

            int piecesx = GetRandomValue(0, 3);
            int piecesy = GetRandomValue(0, 3);
            while (gameMatrix[piecesy][piecesx] != 0) {
                piecesx = GetRandomValue(0, 3);
                piecesy = GetRandomValue(0, 3);
            }
            gameMatrix[piecesy][piecesx] = 2;
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
        if (isGameOver) {
            DrawText("GAMEOVER", 245, 355, 50, BLACK);
            DrawText("GAMEOVER", 250, 350, 50, WHITE);
        }
        /* memset(buffer, 0, 16);
        DrawText(itoa(scoreboard, buffer, 10), 10, 30, 20, BLACK); */

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
