#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#define PI 3.14
int  main()
{
	int i;
	int R,G,B;
	double a;
	int x, y;

	initgraph(640,480);
	for(i=0;i<10;i++)
       for(a=0;a<PI*2;a+=0.0001)	{
		x=(int)(i*30*cos(a)+320);
		y=(int)(i*30*sin(a)+240);
		R=(int)(a*i*25.5/(2*PI));
		setcolor(RGB(R,0,0));
		line(320,240,x,y);
	}
	getch();
	closegraph();
    return 0;
}