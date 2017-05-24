#include<stdio.h>
#include<time.h>
#include "vstub.h"
#include <conio.h>
#include <math.h>
namespace std
{
	float z = 50, dz, x = 5, dx = 1, y = 270, dy = 4 / 3.0;

	float f1(float xx)
	{
		return sin(xx*xx + z) / (abs(xx) + 1);
	}

	float f2(float xx)
	{
		return sin(xx*xx + z) / (abs(xx) + 1);

	}

	int main()
	{
		dz = sqrt(dx*dx + dy*dy);
		int lim[2][800];
		for (int i = 0; i < 800; i++)
		{
			lim[0][i] = -700;
			lim[1][i] = 900;
		}

		int scale_x = 57, shift_x = 150, scale_y = 120;
		dx = 2, dy = 2;
		float dX = 1.0 / 60;
		setcolor(16, 65, 200);
		for (int i = 0; i < 100; i++)
		{
			for (float X = -2.5; X < 2.5; X += dX)
			{
				if (((int)(shift_x + scale_x*(X + dX) + x) <= 400) && (int)(y + scale_y*f2(X + dX)) > lim[0][(int)(shift_x + scale_x*(X + dX) + x)] || (int)(y + scale_y*f2(X + dX)) < lim[1][(int)(shift_x + scale_x*(X + dX) + x)])
				{
					putline((int)(shift_x + scale_x*X + x), (int)(y + scale_y*f2(X)), (int)(shift_x + scale_x*(X + dX) + x), (int)(y + scale_y*f2(X + dX)));
					if ((int)(y + scale_y*f2(X + dX)) > lim[0][(int)(shift_x + scale_x*(X + dX) + x)]) lim[0][(int)(shift_x + scale_x*(X + dX) + x)] = (int)(y + scale_y*f2(X + dX));
					if ((int)(y + scale_y*f2(X + dX)) < lim[1][(int)(shift_x + scale_x*(X + dX) + x)]) lim[1][(int)(shift_x + scale_x*(X + dX) + x)] = (int)(y + scale_y*f2(X + dX));
				}
			}
			x += dx;
			y -= dy;
			z += sqrt((dx / 40)*(dx / 40) + (dy / 40)*(dy / 40));
		}
		TFlush();
		GFlush();
		vgetchar();
		_getch();
		return 0;
	}
}
