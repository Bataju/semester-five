#include<iostream>
#include<graphics.h>
#include<cmath>

const int xmin = 20;
const int xmax = 400;
const int ymin = 20;
const int ymax = 400;

const int center = 0;
const int left = 1;
const int right = 2;
const int bottom = 4;
const int top = 8;

int assignCode(float x, float y)
{
	int code = 0;
	if(x<xmin)
	{
		code = code|left; //bitwise or
	}
	else if(x>xmax)
	{
		code = code | right; //bitwise or
	}
	if(y<ymin)
	{
		code = code | top;
	}
	else if(y>ymax)
	{
		code = code | bottom;
	}
	return code;
}

void cohenSutherland(float x1, float y1, float x2, float y2)
{
	float m,x,y;
	int codeOutside;
	int codePoint1 = assignCode(x1, y1);
	int codePoint2 = assignCode(x2, y2);
	
	if((codePoint1 & codePoint2) != 0)
	{
		std::cout<<"The line falls completely outside the region"<<std::endl;
		return;
	}
	
	while(codePoint1!=0 || codePoint2 != 0) //both must be equal to 0
	{
		m = (y2-y1)/(x2-x1);
		
		if(codePoint1 != 0)
			codeOutside = codePoint1;
		else
			codeOutside = codePoint2;
		
		if((codeOutside & top)!=0)//intersects top line (ymin)
		{
			y = ymin;
			x = x1 + (y - y1) / m;
		}
		else if((codeOutside & bottom)!=0)
		{
			y = ymax;
			x = x1 + (y-y1) / m;
		}
		else if((codeOutside & left)!=0)
		{
			x = xmin;
			y = y1 + m * (x-x1);
		}
		else if((codeOutside&right)!=0)
		{
			x = xmax;
			y = y1 + m*(x-x1);
		}
		
		if(codeOutside == codePoint1)
		{
			x1 = static_cast<int>(x);
			y1 = static_cast<int>(y);
			codePoint1 = assignCode(x1, y1);
		}
		else
		{
			x2 = static_cast<int>(x);
			y2 = static_cast<int>(y);
			codePoint2 = assignCode(x2, y2);
		}
	}
	std::cout<<"Coordinates of endpoints of line"<<std::endl;
	std::cout<<"x1: "<<x1<<", y1: "<<y1<<" and x2: "<<x2<<", y2: "<<y2<<std::endl;
	line(int(x1), int(y1), int(x2), int(y2));
}

int main()
{
	float x1, y1, x2, y2;
	std::cout<<"Enter (x1, y1): ";
	std::cin>>x1>>y1;
	std::cout<<"Enter (X2, y2): ";
	std::cin>>x2>>y2;
	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	
	//the defined region
	rectangle(xmin, ymin, xmax, ymax);
	line(x1, y1, x2, y2);
	delay(3000);
	
	clearviewport();
	rectangle(xmin, ymin, xmax, ymax);
	cohenSutherland(x1, y1, x2, y2);
	
	getch();
	closegraph();
	return 0;
}
