#include <graphics.h>
#include <conio.h>
#define screenx 640
#define screeny 480
#define step 10
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
int move(Ball *ball,int W,int H,char c){   //调整球的位置，即新球设置一个新位置
      if((ball->y + ball->r >=H)&&c=='s'||(ball->y - ball->r <=0)&&c=='w'||(ball->x + ball->r >=W)&&c=='d'||(ball->x - ball->r <=0)&&c=='a')
		  return 0;
	  switch(c)
	  {
	      case 'a' : case 'A' : ball->x-=step; break;
		  case 's' : case 'S' : ball->y+=step; break;
		  case 'd' : case 'D' : ball->x+=step; break;
		  case 'w' : case 'W' : ball->y-=step; break;
	  }
}
void main(){
	initgraph(screenx,screeny);
	Ball ball;
	initBall(&ball,50,50,20);
	while(1){             //判断是否有用户按键
		draw(ball);
		if(kbhit()){
			char c;
			c=getch();
		    clear(ball);
		    move(&ball,screenx,screeny,c);
		}
	}
	closegraph();
}
