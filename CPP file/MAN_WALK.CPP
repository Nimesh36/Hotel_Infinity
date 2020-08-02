#include<iostream>
#include<stdio.h>
#include<graphics.h>
#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight*0.75

int ldisp=0;

void DrawMan(int x,int ldisp)
{
//head
setcolor(WHITE);
setfillstyle(SOLID_FILL,BROWN);
circle(x,GroundY-90,10);
line(x,GroundY-80,x,GroundY-30);
//hand
floodfill(x,GroundY-90,WHITE);
setcolor(WHITE);
setfillstyle(SOLID_LINE,YELLOW);
line(x,GroundY-70,x+10,GroundY-60);
line(x,GroundY-65,x+10,GroundY-55);
line(x+10,GroundY-60,x+20,GroundY-70);
line(x+10,GroundY-55,x+20,GroundY-70);
//legs
line(x,GroundY-30,x+ldisp,GroundY);
line(x,GroundY-30,x-ldisp,GroundY);
}

int main()
{
  int gd=DETECT,gm,x=0;
  //Change BGI directory according to yours
  initgraph(&gd,&gm,"");
  while(!kbhit())
  {
   //Draw Ground
   line(0,GroundY,ScreenWidth,GroundY);
   ldisp=(ldisp+2)%20;
   DrawMan(x,ldisp);
   delay(75);
   cleardevice();
   x=(x+2)%ScreenWidth;
}
  return 0;
}


