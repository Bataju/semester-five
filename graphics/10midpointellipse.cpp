#include<iostream>
#include<graphics.h>

using namespace std;

int main()
{
	int h, k, a, b;
	int x0, y0, xk, yk;
	float p10, p20, p1k, p2k;
	int gd = DETECT, gm;
	cout<<"Enter the center(h, k): ";
	cin>>h>>k;
	cout<<"Enter the x-radius and the y-radius: ";
	cin>>a>>b;
	x0 = 0;
	y0 = b;
	p10 = b*b - b*a*a+a*a/4;
	xk = x0;
	yk = y0;
	p1k = p10;
	initgraph(&gd, &gm, (char*)"");
	while(2*xk*b*b<2*yk*a*a)
	{
		putpixel(xk+h, yk+k, GREEN);
		putpixel(-xk+h, yk+k, GREEN);
		putpixel(xk+h, -yk+k, GREEN);
		putpixel(-xk+h, -yk+k, GREEN);
		if(p1k<=0)
		{
			xk = xk+1;
			yk = yk;
			p1k = p1k + 2*xk*b*b+b*b;
		}
		else
		{
			xk = xk+1;
			yk = yk-1;
			p1k = p1k + 2*xk*b*b - 2*yk*a*a+b*b;
		}
		delay(50);
	}
	x0 = xk;
	y0 = yk;
	p20 = (x0+0.5)*(x0+0.5)*b*b+(y0-1)*(y0-1)*a*a-a*a*b*b;
	p2k = p20;
	while(yk>0)
	{
		putpixel(xk+h, yk+k, GREEN);
		putpixel(-xk+h, yk+k, GREEN);
		putpixel(xk+h, -yk+k, GREEN);
		putpixel(-xk+h, -yk+k, GREEN);
		if(p2k<=0)
		{
			xk = xk + 1;
			yk = yk - 1;
			p2k = p2k + 2*xk*b*b - 2*yk*a*a + a*a;
		}
		else
		{
			xk = xk;
			yk = yk -1;
			p2k = p2k - 2*yk*a*a + a*a;
		}
		delay(50);
	}
	getch();
	closegraph();
	return 0;
}
