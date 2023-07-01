#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
	float x0, y0, x1, y1, xk, yk, delx, dely, steps, xinc, yinc;
	int gd = DETECT, gm;
	cout<<"Enter x0 and y0: ";
	cin>>x0>>y0;
	cout<<"Enter x1 and y1: ";
	cin>>x1>>y1;
	delx = x1 - x0;
	dely = y1 - y0;
	if(abs(delx)>abs(dely))
		steps = abs(delx);
	else
		steps = abs(dely);
	xinc = delx/steps;
	yinc = dely/steps;
	
	xk=x0;
	yk=y0;
	initgraph(&gd, &gm, (char*)"");
	for(int i=0; i<steps; i++)
	{
		putpixel(int(xk), int(yk), GREEN);
		xk += xinc;
		yk += yinc;
		delay(10);
	}
	closegraph();
	
	xk=x0;
	yk=y0;
	cout<<"xk\tyk\txk+1\tyk+1"<<endl;
	for(int i=0; i<steps; i++)
	{
		cout<<int(xk)<<"\t"<<int(yk)<<"\t"<<int(xk+xinc)<<"\t"<<int(yk+yinc)<<endl;
		xk += xinc;
		yk += yinc;
	}
	return 0;
}
