#include "raylib.h"
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    // 1 Blanco, 2 Verde, 3 Rojo, 4 Azul, 5 Naranja, 6 Amarillo
    Color colors[] = {BROWN, WHITE, GREEN, RED, BLUE, ORANGE, YELLOW};
    //                  0      1      2     3     4      5       6
    int cubeArray[9][12] = {
        {0, 0, 0,   1, 1, 1,    0, 0, 0,    0, 0, 0},
        {0, 0, 0,   1, 1, 1,    0, 0, 0,    0, 0, 0},
        {0, 0, 0,   1, 1, 1,    0, 0, 0,    0, 0, 0},

        {2, 2, 2,   3, 3, 3,    4, 4, 4,    5, 5, 5},
        {2, 2, 2,   3, 3, 3,    4, 4, 4,    5, 5, 5},
        {2, 2, 2,   3, 3, 3,    4, 4, 4,    5, 5, 5},

        {0, 0, 0,   6, 6, 6,    0, 0, 0,    0, 0, 0},
        {0, 0, 0,   6, 6, 6,    0, 0, 0,    0, 0, 0},
        {0, 0, 0,   6, 6, 6,    0, 0, 0,    0, 0, 0}
    };

    InitWindow(screenWidth, screenHeight, "Rubik's Cube");
    SetTargetFPS(60);
    

    int squareSideSize = screenWidth/24;
    int squarePositionY = screenHeight/18, squarePositionX = screenWidth/24;

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(BLACK);

            for(int i = 0; i<9; i++)
                for(int j = 0; j<12; j++){
                    DrawRectangle(squarePositionX*j+squareSideSize/2*(j+1), squarePositionY*i+squareSideSize/2*(i+1), squareSideSize, squareSideSize, colors[cubeArray[i][j]]);
                }

        EndDrawing();
    }
    CloseWindow();

    return 0;
}