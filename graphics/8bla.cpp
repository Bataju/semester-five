#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
	int x0, y0, x1, y1, xk, yk, delx, dely, p0, pk;
	int a, b;
	int gd = DETECT, gm;
	cout<<"Enter x0 and y0: ";
	cin>>x0>>y0;
	cout<<"Enter x1 and y1: ";
	cin>>x1>>y1;
	delx = abs(x1 - x0);
	dely = abs(y1 - y0);
	xk = x0;
	yk = y0;
	initgraph(&gd, &gm, (char*)"");
	if(x1>x0)
		a=1;
	else
		a=-1;
	if(y1>y0)
		b=1;
	else
		b=-1;
	if(delx>=dely)
	{
		p0 = 2*dely-delx;
		pk = p0;
		for(int k=0; k<delx; k++)
		{
			putpixel(int(xk), int(yk), RED);
			if(pk<=0)
			{
				xk = xk+a;
				pk = pk + 2*dely;
			}
			else
			{
				xk = xk + a;
				yk = yk + b;
				pk = pk + 2*dely - 2*delx;
			}
			delay(10);
		}
	}
	else
	{
		p0 = 2*delx-dely;
		pk = p0;
		for(int k=0; k<dely; k++)
		{
			putpixel(int(xk), int(yk), RED);
			if(pk<=0)
			{
				yk = yk + b;
				pk = pk + 2*delx;
			}
			else
			{
				xk = xk + a;
				yk = yk + b;
				pk = pk + 2*delx - 2*dely;
			}
			delay(10);
		}		
	}
	closegraph();
	
	xk=x0;
	yk=y0;
	cout<<"\nxk\tyk\txk+1\tyk+1"<<endl;
	if(x1>x0)
		a=1;
	else
		a=-1;
	if(y1>y0)
		b=1;
	else
		b=-1;
	if(delx>=dely)
	{
		p0 = 2*dely-delx;
		pk = p0;
		for(int k=0; k<delx; k++)
		{
			if(pk<=0)
			{
				cout<<int(xk)<<"\t"<<int(yk)<<"\t"<<int(xk+a)<<"\t"<<int(yk)<<endl;
				xk = xk+a;
				pk = pk + 2*dely;
			}
			else
			{
				cout<<int(xk)<<"\t"<<int(yk)<<"\t"<<int(xk+a)<<"\t"<<int(yk+b)<<endl;
				xk = xk + a;
				yk = yk + b;
				pk = pk + 2*dely - 2*delx;
			}
			delay(10);
		}
	}
	else
	{
		p0 = 2*delx-dely;
		pk = p0;
		for(int k=0; k<dely; k++)
		{
			if(pk<=0)
			{
				cout<<int(xk)<<"\t"<<int(yk)<<"\t"<<int(xk)<<"\t"<<int(yk+b)<<endl;
				yk = yk + b;
				pk = pk + 2*delx;
			}
			else
			{
				cout<<int(xk)<<"\t"<<int(yk)<<"\t"<<int(xk+a)<<"\t"<<int(yk+b)<<endl;
				xk = xk + a;
				yk = yk + b;
				pk = pk + 2*delx - 2*dely;
			}
			delay(10);
		}		
	}
	return 0;
}
