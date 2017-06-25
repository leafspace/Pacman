#include <graphics.h>
#include <conio.h>
#define screenx 640
#define screeny 480
typedef struct{
    int x;     //球心坐标
	int y;
	int r;     //球半径
	int dx;    //x方向上的偏移
	int dy;    //y方向上的偏移
}Ball;        //定义一个球类型
void initBall(Ball *ball,int x,int y,int r){   //初始化一个球
	ball->x=x;
	ball->y=y;
	ball->r=r;
} 
void draw(Ball ball){    //画一个实心球
	setfillcolor(0x0000ff);
	setcolor(0x0000ff);
	fillcircle(ball.x,ball.y,ball.r);
}
void clear(Ball ball){   //擦除球
	setfillcolor(0x000000);
	setcolor(0x000000);
	fillcircle(ball.x,ball.y,ball.r);
}
void move(Ball *ball,int W,int H){   //调整球的位置，即新球设置一个新位置
	  static int wf=10,hf=10;
      if((ball->y + ball->r >=H)||(ball->y - ball->r <=0))
		  wf=-wf;
	  if((ball->x + ball->r >=W)||(ball->x - ball->r <=0))
		  hf=-hf;
	  ball->x+=hf;
	  ball->y+=wf;
}
void main(){
	initgraph(screenx,screeny);
	Ball ball;
	initBall(&ball,50,50,20);
	while(!kbhit()){             //判断是否有用户按键
	    draw(ball);
		Sleep(100);
		clear(ball);
		move(&ball,screenx,screeny);
	}
	closegraph();
}