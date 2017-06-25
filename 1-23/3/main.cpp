#include <graphics.h>
#include <conio.h>
#define screenx 640
#define screeny 480
typedef struct{
    int x;     //��������
	int y;
	int r;     //��뾶
	int dx;    //x�����ϵ�ƫ��
	int dy;    //y�����ϵ�ƫ��
}Ball;        //����һ��������
void initBall(Ball *ball,int x,int y,int r){   //��ʼ��һ����
	ball->x=x;
	ball->y=y;
	ball->r=r;
} 
void draw(Ball ball){    //��һ��ʵ����
	setfillcolor(0x0000ff);
	setcolor(0x0000ff);
	fillcircle(ball.x,ball.y,ball.r);
}
void clear(Ball ball){   //������
	setfillcolor(0x000000);
	setcolor(0x000000);
	fillcircle(ball.x,ball.y,ball.r);
}
void move(Ball *ball,int W,int H){   //�������λ�ã�����������һ����λ��
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
	while(!kbhit()){             //�ж��Ƿ����û�����
	    draw(ball);
		Sleep(100);
		clear(ball);
		move(&ball,screenx,screeny);
	}
	closegraph();
}