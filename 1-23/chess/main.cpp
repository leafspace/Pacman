#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <graphics.h>
#define ROW 8    /*表示棋盘的行数*/
#define COL 8     /*表示棋盘的列数*/
#define W 40      /*表示一个方块的宽度*/
#define H 40       /*表示一个方块的高度*/
#define ORGX 50   /*表示棋盘在屏幕上的起始x坐标*/
#define ORGY 50   /*表示棋盘在屏幕上的起始y坐标*/
typedef struct
{
	double x;
	double y;
	char color[6];
}Chess;
int step;
Chess zs;
void drawinformation(void);
void drawchessboard(void);
void drawblackboard(void);
void cleanchess(void);
void drawchess(void);
void runchess(void);
void main()
{
	initgraph(ROW*W+290,COL*H+150);
	drawchessboard();
	drawblackboard();
	zs.x=ORGX+2.5*W;
	zs.y=ORGY+3.5*H;
	strcpy(zs.color,"RED");
	runchess();
	getch();
	closegraph();
}
void drawinformation(void)
{
	char str[5];
	setcolor(RGB(17,119,232));
	setfillcolor(RGB(17,119,232));
	//fillrectangle(ORGX+COL*W+50,ORGY+52,ORGX+COL*W+210,ORGY+102);
	sprintf(str,"%d",step);
	settextstyle(38,0,"");
	outtextxy(ORGX+COL*W+50,ORGY+52,str);

	setcolor(RGB(17,119,232));
	setfillcolor(RGB(17,119,232));
	//fillrectangle(ORGX+COL*W+50,ORGY+184,ORGX+COL*W+210,ORGY+234);
	sprintf(str,"%d",0);
	settextstyle(38,0,"");
	outtextxy(ORGX+COL*W+50,ORGY+184,str);
}
void drawchessboard(void)
{
	int i,j;
	for(i=0;i<ROW;i++)
		for(j=0;j<COL;j++){
			if((i+j)%2)
				setfillcolor(RGB(255,255,255));
			else
				setfillcolor(RGB(0,0,0));
			fillrectangle(ORGX+j*W,ORGY+i*H,ORGX+(j+1)*W,ORGY+(i+1)*H);
		}
}
void drawblackboard(void)
{
	setcolor(RGB(26,223,70));
	setfillcolor(RGB(26,223,70));
	//fillrectangle(ORGX+COL*W+50,ORGY,ORGX+COL*W+210,ORGY+50);
	settextstyle(38,0,"");
	outtextxy(ORGX+COL*W+50,ORGY,"YOU STEP");

	//setcolor(RGB(17,119,232));
	//setfillcolor(RGB(17,119,232));
	//fillrectangle(ORGX+COL*W+50,ORGY+52,ORGX+COL*W+210,ORGY+102);

	setcolor(RGB(26,223,70));
	setfillcolor(RGB(26,223,70));
	//fillrectangle(ORGX+COL*W+50,ORGY+132,ORGX+COL*W+210,ORGY+182);
	settextstyle(38,0,"");
	outtextxy(ORGX+COL*W+50,ORGY+132,"YOU SCORE");

	//setcolor(RGB(17,119,232));
	//setfillcolor(RGB(17,119,232));
	//fillrectangle(ORGX+COL*W+50,ORGY+184,ORGX+COL*W+210,ORGY+234);
}
void cleanchess(void)
{
	double wz;
	wz=zs.x+zs.y-ORGX-ORGY;
	wz=wz/H;
	if((int)wz%2){
		setcolor(RGB(0,0,0));
		setfillcolor(RGB(0,0,0));	
	}
	else{
		setcolor(RGB(255,255,255));
		setfillcolor(RGB(255,255,255));
	}
	fillcircle(zs.x,zs.y,W<H?W/2-2:H/2-2);
}
void drawchess(void)
{
	if(strcmp(zs.color,"RED")==0){
		setcolor(RGB(255,0,0));
		setfillcolor(RGB(255,0,0));
	}
	else{
		setcolor(RGB(0,0,255));
		setfillcolor(RGB(0,0,255));
	}
	fillcircle(zs.x,zs.y,W<H?W/2-2:H/2-2);
}
void runchess(void)
{
	while(1)
	{
		drawchess();
		if(kbhit()){
			char c;
			c=getch();
			cleanchess();
			switch(c)
			{
			    case 'a': if((zs.x-W)>=(ORGX+W/2))         zs.x-=W; drawinformation(); step++; break;
				case 's': if((zs.y+H)<=(ORGY+H*(ROW-0.5))) zs.y+=H; drawinformation(); step++; break;
				case 'd': if((zs.x+W)<=(ORGX+W*(COL-0.5))) zs.x+=W; drawinformation(); step++; break;
				case 'w': if((zs.y-H)>=(ORGY+H/2))         zs.y-=H; drawinformation(); step++; break;
			}
		}
	}
}
