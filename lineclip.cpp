#include <iostream>
#include <graphics.h>

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const int xMin = 50, yMin = 50, xMax = 200, yMax = 150;

int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < xMin)
        code |= LEFT;
    else if (x > xMax)
        code |= RIGHT;

    if (y < yMin)
        code |= BOTTOM;
    else if (y > yMax)
        code |= TOP;

    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int code;
            double x, y;

            if (code1 != 0)
                code = code1;
            else
                code = code2;

            if (code & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } else if (code & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } else if (code & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } else if (code & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            if (code == code1) {
                x1 = static_cast<int>(x);
                y1 = static_cast<int>(y);
                code1 = computeCode(x1, y1);
            } else {
                x2 = static_cast<int>(x);
                y2 = static_cast<int>(y);
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64");

  
    rectangle(xMin, yMin, xMax, yMax);

    int x1 = 30, y1 = 100, x2 = 180, y2 = 10;
    setcolor(BLUE);
    line(x1, y1, x2, y2);

 
    cohenSutherland(x1, y1, x2, y2);

    delay(5000); 

    closegraph();
    return 0;
}

