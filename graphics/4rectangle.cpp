#include<iostream>
#include<graphics.h>

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	rectangle(100, 100, 400, 200);
	getch();
	closegraph();
	return 0;
}
