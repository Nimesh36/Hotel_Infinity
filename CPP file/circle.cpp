#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{

    int gd=DETECT,gm,i,x,y,j,k,l,m,n,A[10];
    char ch;
    initgraph(&gd,&gm,"");
    x=getmaxx();
    y=getmaxy();
    do
    {
    for(i=1;i<16;i++)
    {
        setcolor(i);
        for(m=0;m<25;m++)
        {
            j=rand()%y/2;
            circle(x/2,y/2,j);
            delay(70);
        }
    }
    closegraph();
    }while(false);
    getch();
    return 0;
}
