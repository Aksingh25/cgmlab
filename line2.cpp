#include <iostream>
#include <conio.h>
#include <graphics.h>
int main()
{


int gd =  DETECT , gm;
initgraph(&gd, &gm, (char*)"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64");

line(150, 150, 450, 150);

  getch();
closegraph();
return 0;
}
