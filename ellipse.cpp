#include <iostream>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*) "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64");

    
    int x = 300;  
    int y = 200;  
    int rx = 100;
    int ry = 50;

    
    ellipse(x, y, 0, 360, rx,ry);

    getch();
    closegraph();

    return 0;
}

