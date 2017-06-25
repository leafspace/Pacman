#include <graphics.h>
#include <conio.h>
#define screenx 640
#define screeny 480
#define step 10
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
int move(Ball *ball,int W,int H,char c){   //�������λ�ã�����������һ����λ��
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
	while(1){             //�ж��Ƿ����û�����
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
