#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
	int a, b, r, x0, y0, p0, pk, xk, yk;
	int gd = DETECT, gm;
	cout<<"Enter the center(a, b): ";
	cin>>a>>b;
	cout<<"Enter the radius(r): ";
	cin>>r;
	initgraph(&gd, &gm, (char*)"");
	x0 = 0;
	y0 = r;
	p0 = 1-r;
	xk = x0;
	yk = y0;
	pk = p0;
	while(xk<=yk)
	{
		putpixel(xk+a, yk+b, GREEN);
		putpixel(xk+a, -yk+b, GREEN);
		putpixel(-xk+a, yk+b, GREEN);
		putpixel(-xk+a, -yk+b, GREEN);
		putpixel(yk+a, xk+b, GREEN);
		putpixel(-yk+a, -xk+b, GREEN);
		putpixel(yk+a, -xk+b, GREEN);
		putpixel(-yk+a, xk+b, GREEN);
		if(pk<0)
		{
			xk = xk +1;
			pk = pk + 2 *xk +1;
		}
		else
		{
			xk = xk+1;
			yk = yk-1;
			pk = pk +2*xk - 2*yk + 1;
		}
		delay(50);
	}
	
	closegraph();
	return 0;
}
