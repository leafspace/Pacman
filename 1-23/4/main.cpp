#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#define ESC 27
void main(){
	char c = 0;
	while(1)	{
		if (kbhit()){
	     	c=getch();
			if(c==ESC) break;
		}
		else  c = '.';
		printf("%c", c);
		Sleep(100);
	}
}