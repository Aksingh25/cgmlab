#include <iostream>
#include <graphics.h>

void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, 4);
    putpixel(xc - x, yc + y, 4);
    putpixel(xc + x, yc - y, 4);
    putpixel(xc - x, yc - y, 4);
    putpixel(xc + y, yc + x, 4);
    putpixel(xc - y, yc + x, 4);
    putpixel(xc + y, yc - x, 4);
    putpixel(xc - y, yc - x, 4);
}

void midpointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    drawCircle(xc, yc, x, y);

    while (x < y) {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawCircle(xc, yc, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\libbgi.a");
    int xc, yc, r;

    std::cout << "Enter the center coordinates (x y): ";
    std::cin >> xc >> yc;

    std::cout << "Enter the radius: ";
    std::cin >> r;

    midpointCircle(xc, yc, r);

    delay(5000);
    closegraph();

    return 0;
}

