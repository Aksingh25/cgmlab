#include <iostream>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    
    int left = 100;  
    int top = 50;     
    int right = 300;  
    int bottom = 200; 
  
    rectangle(left, top, right, bottom);

  getch();
 closegraph();
 return 0;
}

