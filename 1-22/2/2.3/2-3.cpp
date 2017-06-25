#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#define WIDTHF 600
#define HEIGHTF 450
#define WIDTHS 580
#define HEIGHTS 435
int startxf,startyf;
int startxs,startys;
void main()
{
	int i;
	int hc=(HEIGHTF-HEIGHTS)/2,wc=(WIDTHF-WIDTHS)/2;
	initgraph(640,480);
	startxf=(640-WIDTHF)/2;
	startyf=(480-HEIGHTF)/2;
	rectangle(startxf,startyf,startxf+WIDTHF,startyf+HEIGHTF);

	startxs=(640-WIDTHS)/2;
	startys=(480-HEIGHTS)/2;
    rectangle(startxs,startys,startxs+WIDTHS,startys+HEIGHTS);

    for(i=0;i<=WIDTHS/wc;i++){
		line(startxs+i*wc,startyf,startxs+i*wc,startyf+hc);
		line(startxs+i*wc,startys+HEIGHTS,startxs+i*wc,startys+hc+HEIGHTS);
	}
    for(i=0;i<=HEIGHTS/hc;i++){
		line(startxf,startys+i*hc,startxf+wc,startys+i*hc);
		line(startxs+WIDTHS,startys+i*hc,startxs+WIDTHS+wc,startys+i*hc);
	}
    getch();
	closegraph();
}