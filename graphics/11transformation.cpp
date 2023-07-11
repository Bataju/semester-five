#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

void drawTriangle(int x0, int y0, int  x1, int y1, int x2, int y2)
{
	line(200+x0, 200-y0, 200+x1, 200-y1);
	line(200+x1, 200-y1, 200+x2, 200-y2);
	line(200+x0, 200-y0, 200+x2, 200-y2);
}

int* matxMult(int** matx1, int* matx2)
{
	int* matRes;
	for(int i=0; i<3; i++)
	{
		matRes[i] = 0;
		for(int j=0; j<3; j++)
		{
			matRes[i] = matRes[i] + matx1[i][j] * matx2[j];
		}
	}
	return matRes;
}

int main()
{
	int choice, x0, y0, x1, y1, x2, y2;
	int gd = DETECT, gm;
	int quit = 0;
	cout<<"Enter vertex 1 of triangle(x0 and y0): ";
	cin>>x0>>y0;
	cout<<"Enter vertex 2 of triangle(x1 and y1): ";
	cin>>x1>>y1;
	cout<<"Enter vertex 3 of triangle(x2 and y2): ";
	cin>>x2>>y2;
	
	initgraph(&gd, &gm, (char*)"");
	line(200, 0, 200, 400);
	line(0, 200, 400, 200);
	drawTriangle(x0, y0, x1, y1, x2, y2);
	
	while(!quit)
	{
		cout<<"1. Translation\n2. Rotation\n3. Reflection\n4. Scaling\n5. Exit\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				int xt, yt;
				cout<<"Enter translation vector: ";
				cin>>xt>>yt;
				drawTriangle(x0+xt, y0+yt, x1+xt, y1+yt, x2+xt, y2+yt);
				break;
			}
			case 2:
			{
				int angle;
				cout<<"Enter rotation angle: ";
				cin>>angle;
				float rad = M_PI/180 *angle;
				drawTriangle(x0*cos(rad)-y0*sin(rad), x0*sin(rad)+y0*cos(rad), x1*cos(rad)-y1*sin(rad), x1*sin(rad)+y1*cos(rad), x2*cos(rad)-y2*sin(rad), x2*sin(rad)+y2*cos(rad));
				break;
			}
			case 3:
			{
				int k;
				cout<<"1: Reflection about x-axis\n2: Reflection about y-axis\nEnter your choice: ";
				cin>>k;
				if(k==2)//about yaxis
				{
					drawTriangle(-x0, y0, -x1, y1, -x2, y2);
				}
				else//about xaxis
				{
					drawTriangle(x0, -y0, x1, -y1, x2, -y2);
				}
				break;
			}
			case 4:
			{
				int k;
				cout<<"Enter scaling factor: ";
				cin>>k;
				drawTriangle(x0*k, y0*k, x1*k, y1*k, x2*k, y2*k);
				break;
			}
			case 5:
			{
				quit = 1;
				break;
			}	
		}
	}
	getch();
	closegraph();
	return 0;
}
