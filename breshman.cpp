#include<iostream>
#include<graphics.h>
#include<conio.h>

int main()
{
    int x1, y1, x2, y2, p, dx, dy, k;
    int gd = DETECT, gm;
    
    initgraph(&gd, &gm,(char*)"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\libbgi.a");
    
    std::cout << "Enter the value of x1, y1: ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the value of x2, y2: ";
    std::cin >> x2 >> y2;
    
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 * dy - dx;
    
    putpixel(x1, y1, 3);
    
    for (k = 0; k < dx; k++)
    {
        if (p < 0)
        {
            x1++;
            p = p + 2 * dy;
        }
        else
        {
            x1++;
            y1++;
            p = p + 2 * dy - dx;
        }
        putpixel(x1, y1, 3);
        delay(50);
    }
    
    getch();
    closegraph();
    
    return 0;
}
