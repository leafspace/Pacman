#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#define WIDTH   150     /*矩形的宽度*/
#define HEIGHT  100     /*矩形的高度*/
int startX,startY;      /*矩形的左上角坐标*/
int maxX;
int maxY;

void init();       /*图形模式的初始化*/
void showText();  /*显示文本*/
void drawK();    /*画图形*/


int  main(){
	init(); 
	showText();
	drawK();
	closegraph();
    return 0;
}
void init(){
	initgraph(640,480);
	maxX = getmaxx();
	maxY = getmaxy();

    setbkcolor(BLACK);    /*设置背景色为黑色*/
    cleardevice();          /*清屏*/
}
void showText(){
    char str[50];
	sprintf(str,"(%d,%d)",maxX,maxY);    /*将要显示的分辩率以字符串形式保存到str*/
	outtextxy(maxX/4,maxY/4,str);        /*在指定位置显示字符串str*/
}
void drawK(){
	
	startX = (maxX-WIDTH)/2;
	startY = (maxY-HEIGHT)/2;

	setcolor(WHITE);

	rectangle(startX,startY,startX+WIDTH,startY+HEIGHT);

	setcolor(YELLOW);

	line(startX,startY,startX+WIDTH,startY+HEIGHT);
	line(startX+WIDTH,startY,startX,startY+HEIGHT);

	setcolor(RED);

	circle(maxX/2,maxY/2,30);
    getch();    //暂停，任意健继续
}
