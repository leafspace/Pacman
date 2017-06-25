#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#define PI 3.14
void drawmonth(void);
void main()
{
	int i;
	initgraph(640,480);
    for(i=0;;i++){
		if(i%2){
		    setfillcolor(0x0000ff);
            fillcircle(320,240,200);
		}
		else{
			setcolor(0x000000);
            drawmonth();
		}
		Sleep(100);
	}
	getch();
    closegraph();
}
void drawmonth(void)
{
	double a;
	int x,y;
	/*for(a=PI*1.25;a>PI*0.75;a-=0.0001){
		x=(int)(200*cos(a)+320);
		y=(int)(200*sin(a)+240);
		if(f)
			setcolor(0x0000ff);
		else
			setcolor(0x000000);
		line(320, 240, x, y);
	  }*/
	for(a=0;a<PI*0.25;a=a+0.0001){
        x=(int)(200*cos(a+PI)+320);
		y=(int)(200*sin(a+PI)+240);
		line(320, 240, x, y);
        x=(int)(200*cos(PI-a)+320);
		y=(int)(200*sin(PI-a)+240);
		line(320, 240, x, y);
	}
}