#include<iostream>
#include<graphics.h>

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	line(50, 50, 100, 100);
	circle(150, 150, 20);
	rectangle(200, 200, 400, 300);
	getch();
	closegraph();
	return 0;
}
