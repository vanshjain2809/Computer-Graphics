#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
struct Point{
int x,y;
};
void drawPoly(Point ver[],int n)
{ for(int i=0;i<n;i++)
  {setcolor(BLUE);
   line(ver[i].x,ver[i].y,ver[(i+1)%n].x,ver[(i+1)%n].y);
   }
}
void floodFill4(int x, int y, int fill,int oldcolor){
int current;
current=getpixel(x,y);
if(current==oldcolor)
 {putpixel(x,y,fill);
 delay(10);
 floodFill4(x+1,y,fill,oldcolor);
 floodFill4(x-1,y,fill,oldcolor);
 floodFill4(x,y+1,fill,oldcolor);
 floodFill4(x,y-1,fill,oldcolor);
 }
}
void floodFill8(int x, int y, int fill,int oldcolor){
int current;
current=getpixel(x,y);
if(current==oldcolor)
 {putpixel(x,y,fill);
 delay(10);
 floodFill8(x+1,y,fill,oldcolor);
 floodFill8(x-1,y,fill,oldcolor);
 floodFill8(x,y+1,fill,oldcolor);
 floodFill8(x,y-1,fill,oldcolor);
 floodFill8(x-1,y+1,fill,oldcolor);
 floodFill8(x+1,y+1,fill,oldcolor);
 floodFill8(x+1,y-1,fill,oldcolor);
 floodFill8(x-1,y-1,fill,oldcolor);
 }
}
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
Point polygon[]={{100,100},{100,150},{150,150},{150,80},{170,80},{170,100}},seed={101,101};
 clrscr();
 int n=sizeof(polygon)/sizeof(polygon[0]);
 drawPoly(polygon,n);
 int oldcolor=getpixel(101,101);
 putpixel(150,100,oldcolor);    //for testing flood fill 4 and 8
 putpixel(151,101,BLUE);     //second small semi-polygon not fill in 4connected
 putpixel(149,99,BLUE);      //  get filled in 8 connected method
 floodFill4(seed.x,seed.y,RED,oldcolor);  //change 4 by 8 and check yourself
 getch();
 closegraph();
}


