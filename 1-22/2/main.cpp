#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#define WIDTH   150     /*���εĿ��*/
#define HEIGHT  100     /*���εĸ߶�*/
int startX,startY;      /*���ε����Ͻ�����*/
int maxX;
int maxY;

void init();       /*ͼ��ģʽ�ĳ�ʼ��*/
void showText();  /*��ʾ�ı�*/
void drawK();    /*��ͼ��*/


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

    setbkcolor(BLACK);    /*���ñ���ɫΪ��ɫ*/
    cleardevice();          /*����*/
}
void showText(){
    char str[50];
	sprintf(str,"(%d,%d)",maxX,maxY);    /*��Ҫ��ʾ�ķֱ������ַ�����ʽ���浽str*/
	outtextxy(maxX/4,maxY/4,str);        /*��ָ��λ����ʾ�ַ���str*/
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
    getch();    //��ͣ�����⽡����
}
