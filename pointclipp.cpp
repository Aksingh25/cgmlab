#include <iostream>
#include <graphics.h>

const int INSIDE = 0; 
const int LEFT = 1;   
const int RIGHT = 2;  
const int BOTTOM = 4;
const int TOP = 8;    


int xmin = 100;
int ymin = 100;
int xmax = 300;
int ymax = 200;


int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64");

    int x, y;

    std::cout << "Enter the coordinates of the point (x y): ";
    std::cin >> x >> y;

    int code = computeCode(x, y);

    while (code != INSIDE) {
        if (code & LEFT) {
            x = xmin;
            y += (ymin - y) * (x - xmin) / (x - xmin);
        } else if (code & RIGHT) {
            x = xmax;
            y += (ymin - y) * (x - xmin) / (x - xmin);
        } else if (code & BOTTOM) {
            y = ymin;
            x += (xmin - x) * (y - ymin) / (y - ymin);
        } else if (code & TOP) {
            y = ymax;
            x += (xmin - x) * (y - ymin) / (y - ymin);
        }

        code = computeCode(x, y);
    }

   
    putpixel(x, y, WHITE);

    getch();

    
    closegraph();

    return 0;
}

