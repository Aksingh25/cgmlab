#include <iostream>
#include <conio.h>
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*) "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64");


    circle(320, 240, 100);


    circle(270, 190, 15);
    circle(370, 190, 15);

    arc(320, 240, 200, 340, 50);

    getch();
    closegraph();
    return 0;
}

