#include "raylib.h"

void DRAW_RUBIKS_CUBE(int cubeArray[9][12], Vector3 &pos, Vector3 &size, Color colors[]){
    for(int i = 0; i<9; i++)
        for(int j = 0; j<12; j++)
            if(cubeArray[i][j]!=0){
                // X Pos && X Size
                if (j < 3 || (j > 5 && j < 9)){
                    pos.x = 1.75f-1.75f*(j/3);
                    // basicamente, si el parentesis da 0, el resultado sera positivo, si da 2, sera negativo
                    size.x = 0.1f;
                }
                else{
                    pos.x = 1.1f-1.1f*(j%3);
                    size.x = 1.0f;
                }

                // Y Pos && Y Size
                if (i < 3 || i > 5){
                    pos.y = 1.75f-1.75f*(i/3);
                    // basicamente, si el parentesis da 0, el resultado sera positivo, si da 2, sera negativo
                    size.y = 0.1f;
                }
                else{
                    pos.y = 1.1f-1.1f*(i%3);
                    size.y = 1.0f;
                }

                // Z Pos && Z Size
                if ( (i >= 3 && i <= 5) && ( (j >= 3 && j <= 5 ) || (j >= 9 ) && (j <= 11)) ){
                    pos.z = 1.75f*2-1.75f*(j/3);
                    // basicamente, si el parentesis da 0, el resultado sera positivo, si da 2, sera negativo
                    size.z = 0.1f;
                }
                else if(j >= 3 && j <= 5){
                    pos.z = 1.1f-1.1f*(i%3);
                    size.z = 1.0f;
                }
                else{
                    pos.z = 1.1f-1.1f*(j%3);
                    size.z = 1.0f;
                }
                
                DrawCube(pos, size.x, size.y, size.z, colors[cubeArray[i][j]]);
                DrawCubeWires(pos, size.x, size.y, size.z, DARKGRAY);
            }
    
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                DrawCube((Vector3){1.13f-1.13f*i,1.13f-1.13f*j,1.13f-1.13f*k}, 1.13f, 1.13f, 1.13f, BLACK);
                // me ha costado muchisimo calcular esto por alguna razon pero es basicamente el relleno del cubo
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    // 1 Blanco, 2 Verde, 3 Rojo, 4 Azul, 5 Naranja, 6 Amarillo
    Color colorsList[] = {BROWN, WHITE, GREEN, RED, BLUE, ORANGE, YELLOW};
    //                  0      1      2     3     4      5       6
    int rubikArray[9][12] = {
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
    
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type
    DisableCursor(); 

    Vector3 defaultPos = {0.0f, 0.0f, 0.0f};
    Vector3 defaultSize = {1.0f, 1.0f, 1.0f};

    while (!WindowShouldClose())
    {
        BeginDrawing();

            UpdateCamera(&camera, CAMERA_FREE);

            ClearBackground(WHITE);

            BeginMode3D(camera);
            
                DRAW_RUBIKS_CUBE(rubikArray, defaultPos, defaultSize, colorsList);
                DrawGrid(10, 1.0f);

            EndMode3D();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}