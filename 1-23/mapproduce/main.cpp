#include <math.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	int x;
	int y;
}Boss;
typedef struct
{
	int x;
	int y;
}Pacman;
Boss b1,b2;
Pacman p1;
int beans;
void main()
{
	FILE *fp;
	int h,l;
	int i;
	char *map;
	char map_name[32]={0};
	srand((unsigned)time(NULL));
	printf("This is the menu of the map folder !\n");
	system("dir");
	printf("Please enter the map name !\n");
	gets(map_name);
	if((fp=fopen(map_name,"w"))==NULL){
		printf("File open error !\n");
		exit(-1);
	}
	printf("Please enter the line and row!\n");
	scanf("%d %d",&h,&l);
	map=(char*)malloc(h*l);
	//setmem(map,h*l,'1');
	for(i=0;*(map+i);i++)
		*(map+i)='1';
	do
	{
		b1.x=rand()%(h-3)+1;
		b1.y=rand()%(l-3)+1;
		b2.x=rand()%(h-3)+1;
		b2.y=rand()%(l-3)+1;
		p1.x=rand()%(h-3)+1;
		p1.y=rand()%(l-3)+1;
		double t1,t2;
		t1=sqrt(pow(p1.x-b1.x,2)+pow(p1.y-b1.y,2));
		t2=sqrt(pow(p1.x-b2.x,2)+pow(p1.y-b2.y,2));
		if(t1>=2&&t2>=2)
			break;
	}while(1);
	printf("(%d,%d)\t(%d,%d)\t(%d,%d)\n",b1.x,b1.y,b2.x,b2.y,p1.x,p1.y);
	*(map+p1.x*l+p1.y)='P';
	*(map+b1.x*l+b1.y)='M';
	*(map+b2.x*l+b2.y)='M';
	bens=rand()%(2*(l+h)-15)+5;

	getch();
}