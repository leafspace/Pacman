#include <math.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <MEMORY.h>
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
typedef struct
{
	int x;
	int y;
}Bean;

Boss b1,b2;
Pacman p1;
int *step;
char *map,*mapt;
int beans;
int h,l;
int search(int m);
void mapcopy(char *m1,char *m2);
int mapjugde(void);
int placejugde(int x,int y,int direction); //1 ио 2 вС 3 об 4 ср 


void main()
{
	FILE *fp;
	int i,j;
	char map_name[32]={0};
	srand((unsigned)time(NULL));
	printf("This is the menu of the map folder !\n");
	system("dir");
	printf("Please enter the map name !\n");
	gets(map_name);
	if(strstr(map_name,".txt")==NULL)
		strcat(map_name,".txt");
	if((fp=fopen(map_name,"w"))==NULL){
		printf("File open error !\n");
		exit(-1);
	}
	printf("Please enter the line and row!\n");
	scanf("%d %d",&h,&l);

	beans=rand()%(2*(l+h)-30)+20;
	step=(int*)malloc(beans*sizeof(int));
	mapt=(char*)malloc(h*l);
	map=(char*)malloc(h*l);
	memset(step,0,beans*sizeof(int));
	memset(map,1,h*l);

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
	*(map+p1.x*l+p1.y)='P';
	*(map+b1.x*l+b1.y)='M';
	*(map+b2.x*l+b2.y)='M';
	
	
	search(0);


	for(i=0;i<h;i++){
		for(j=0;j<l;j++)
			printf("%c",*(map++));
		printf("\n");
	}
	getch();
}


int search(int m)
{
	if(m>=beans){
		if(!mapjugde()){
			mapcopy(map,mapt);
			return 0;
		}
		else{
			mapcopy(mapt,map);		
		}
	}
	else{
		step[m]=1;
		search(m+1);

		step[m]=2;
		search(m+1);

		step[m]=3;
		search(m+1);

		step[m]=4;
		search(m+1);
	}
}

int mapjugde(void)
{
	int x,y;
	int *p;
	p=step;
	x=p1.x;
	y=p1.y;
	while(p){
		if(placejugde(x,y,*p)==0){
			switch(*p)
			{
			    case 1 : y=y-l; break;
				case 2 : x=x-1; break;
				case 3 : y=y+l; break;
				case 4 : x=x+1; break;
			}
		}
		else
			break;
		p++;
	}
	if(p)
		return 1;
	else
		return 0;
}
void mapcopy(char *m1,char *m2)
{
	for(;m2;m1++,m2++)
		*m1=*m2;
}
int placejugde(int x,int y,int direction)
{
	int place;
	place=x*l+y;
	switch(direction)
	{
	    case 1 : place-=l; break;
		case 2 : place-=1; break;
		case 3 : place+=l; break;
		case 4 : place+=1; break;
	}
	if(place%l==0||(place+1)%l==0||place<l-1||place>(h-1)*l)
		return 1;
	if(*(map+place)=='M'||*(map+place)=='P'||*(map+place)=='0')
		return 1;
	return 0;
}
