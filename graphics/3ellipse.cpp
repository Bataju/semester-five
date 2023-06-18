#include<iostream>
#include<graphics.h>

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	ellipse(200, 200, 0, 360, 100, 50);
	getch();
	closegraph();
	return 0;
}
