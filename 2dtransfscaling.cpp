#include <iostream>
#include <graphics.h>

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

void scaleRectangle(int &x1, int &y1, int &x2, int &y2, float scaleX, float scaleY) {
    x1 = static_cast<int>(x1 * scaleX);
    y1 = static_cast<int>(y1 * scaleY);
    x2 = static_cast<int>(x2 * scaleX);
    y2 = static_cast<int>(y2 * scaleY);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64");

    int x1 = 50, y1 = 50, x2 = 150, y2 = 100;

    drawRectangle(x1, y1, x2, y2);

    float scaleX = 1.5, scaleY = 2.0;

   
    scaleRectangle(x1, y1, x2, y2, scaleX, scaleY);


    setcolor(RED);
    drawRectangle(x1, y1, x2, y2);

    delay(5000); 

    closegraph();
    return 0;
}

