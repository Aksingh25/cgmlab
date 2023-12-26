#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, dx, dy, steps, xinc, yinc, i;
    
    initgraph(&gd, &gm, (char*)"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64");
     
    std::cout << "Enter the value of x1 & y1: " << std::endl;
    std::cin >> x1 >> y1;
    
    std::cout << "Enter the value of x2 & y2: " << std::endl ;
    std::cin >> x2 >> y2;
    
    dx = x2 - x1;
    dy = y2 - y1;
    
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    
    xinc = dx / steps;
    yinc = dy / steps;
    
    for (i = 0; i < steps; i++)
    {   
        putpixel(x1, y1, 3);
        x1 = x1 + xinc;
        y1 = y1 + yinc;
        delay(50);
    }
    
    getch();
    closegraph();
    
    return 0;
}

