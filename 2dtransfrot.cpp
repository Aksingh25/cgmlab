#include <iostream>
#include <cmath>
#include <graphics.h>

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

void rotateRectangle(int &x1, int &y1, int &x2, int &y2, float angle) {
    float angleRad = (angle * 3.14159) / 180; 
    int newX1 = static_cast<int>((x1 * cos(angleRad)) - (y1 * sin(angleRad)));
    int newY1 = static_cast<int>((x1 * sin(angleRad)) + (y1 * cos(angleRad)));
    int newX2 = static_cast<int>((x2 * cos(angleRad)) - (y2 * sin(angleRad)));
    int newY2 = static_cast<int>((x2 * sin(angleRad)) + (y2 * cos(angleRad)));

    x1 = newX1;
    y1 = newY1;
    x2 = newX2;
    y2 = newY2;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64");

    int x1 = 50, y1 = 50, x2 = 150, y2 = 100;

    drawRectangle(x1, y1, x2, y2);

    float angle = 45.0;

    rotateRectangle(x1, y1, x2, y2, angle);

    
    setcolor(RED);
    drawRectangle(x1, y1, x2, y2);

    delay(5000); 

    closegraph();
    return 0;
}

