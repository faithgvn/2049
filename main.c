#include <raylib.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    InitWindow(800, 600, "2049 by faithgvn");

    while (!WindowShouldClose()) {
        /* Read Keyboard Inputs */

        /* Do logic */

        /* Draw everthing */

        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
