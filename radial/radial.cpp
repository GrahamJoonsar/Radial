#include "raylib.h"
#include <math.h>

class Pointer{
    public:
        float x, y, radius, startingYPos, startingXPos, length, angle;
        Color color;
        
        void draw(){
            DrawCircle(startingXPos, startingYPos, length, DARKGRAY);
            DrawLine(startingXPos, startingYPos, x, y, WHITE);
            DrawCircle(x, y, radius, color);
        }
        
        void move(){
            //angle = atan2(GetMouseY() - startingYPos, GetMouseX() - startingXPos);
            angle += 0.01;
            if (angle > 2 * M_PI){
                angle = 0;
            }
            x = length * cos(angle) + startingXPos;
            y = length * sin(angle) + startingYPos;
        }
};

Pointer pointer;
Pointer pointer2;
const int screenWidth = 1000;
const int screenHeight = 500;

Pointer pointerSetup(Pointer p, float px, float py, float angle){
    p.x = p.startingXPos = px;
    p.y = p.startingYPos = py;
    p.radius = 10;
    p.length = 200;
    p.x += p.length;
    p.angle = angle;
    p.color = RED;
    return p;
}

int main(void)
{   
    pointer = pointerSetup(pointer, screenWidth/2 - 200, screenHeight/2, 0);
    pointer2 = pointerSetup(pointer2, screenWidth/2 + 200, screenHeight/2, M_PI);

    InitWindow(screenWidth, screenHeight, "Radial");

    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        
        pointer.draw();
        pointer.move();
        
        pointer2.draw();
        pointer2.move();
        
        DrawLine(pointer.x, pointer.y, pointer2.x, pointer2.y, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}