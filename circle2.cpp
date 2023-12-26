#include <iostream>
#include <conio.h>
#include <graphics.h>
int main()
{


int gd =  DETECT , gm;
initgraph(&gd, &gm, (char*)"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64");

circle(300,200,150);







getch();
closegraph();
return 0;
}
