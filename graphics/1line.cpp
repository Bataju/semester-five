#include<iostream>
#include<graphics.h>

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	line(100, 150, 200, 250);
	getch();
	closegraph();
	return 0;
}
