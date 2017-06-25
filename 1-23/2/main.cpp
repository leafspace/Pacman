#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#define PI 3.14
int cirx=320,ciry=240,round=80;
void drawmonth(void);
void clscirl(void);
void main()
{
	int i;
	int f=10;
	void *fp;
	initgraph(640,480);

	setfillcolor(0x0000ff);
	setcolor(0x0000ff);
    fillcircle(cirx,ciry,round);
    setcolor(0x000000);
    drawmonth();			

	fp=malloc(round*round*4);
	getimage(cirx-round,ciry-round,cirx+round,ciry+round,fp);
		if(cirx>640||cirx<0)
			f=-f;
		cirx=cirx+f;
		Sleep(100);


	getch();
    closegraph();
}
void drawmonth(void)
{
	double a;
	int x,y;
	for(a=0;a<PI*0.25;a=a+0.0001){
        x=(int)(round*cos(a+PI)+cirx);
		y=(int)(round*sin(a+PI)+ciry);
		line(cirx, ciry, x, y);
        x=(int)(round*cos(PI-a)+cirx);
		y=(int)(round*sin(PI-a)+ciry);
		line(cirx, ciry, x, y);
	}
}
