#include<iostream>
#include<graphics.h>

int main()
{
	int gd=DETECT, gm;
	int i=0;
	initgraph(&gd, &gm, (char*)"");
	for(i; i<200; i++)
	{
		line(50+i, 50, 150+i, 50);
		line(150+i, 50, 150+i, 100);
		line(50+i, 50, 50+i, 200);
		line(150+i, 100, 220+i, 100);
		line(220+i, 100, 220+i, 200);
		line(50+i, 200, 220+i, 200);
		circle(90+i, 230, 30);
		circle(180+i, 230, 30);
		delay(10);
		cleardevice();
	}
	getch();
	closegraph();
	return 0;
}
