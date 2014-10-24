/*
 * CircelMidpoint.cpp
 *
 * -------------------------------------
 * Draw Circle with Midpoint's Algorithm
 * -------------------------------------
 *
 * Copyright 2014 Imancha <imancha_266@ymail.com>
 *
 */

#include <iostream>
#include <graphics.h>

using namespace std;

void DrawCircle(int xc, int yc, int x, int y){
	putpixel(xc+x, yc+y, MAGENTA);
	putpixel(xc-x, yc+y, MAGENTA);
	putpixel(xc+x, yc-y, MAGENTA);
	putpixel(xc-x, yc-y, MAGENTA);
	putpixel(xc+y, yc+x, MAGENTA);
	putpixel(xc-y, yc+x, MAGENTA);
	putpixel(xc+y, yc-x, MAGENTA);
	putpixel(xc-y, yc-x, MAGENTA);
}

void Circle(int xc, int yc, int r){
  int x = 0;
  int y = r;
  int p = 1 - r;
  int i = 0;

	cout << "\n i \tP \t(x,y) \n --------------------";

	putpixel(xc, getmaxy()-yc, MAGENTA);

  while(x < y){
		DrawCircle(xc, getmaxy()-yc, x, y);
		x++;

		cout << "\n " << i++ << "\t" << p << "\t";

		if(p < 0){
			p += 2 * x + 1;
		}else{
			y--;
			p += 2 * (x - y) + 1;
		}

		cout << "(" << x << "," << y << ")";
		DrawCircle(xc, getmaxy()-yc, x, y);
		delay(20);
	}
	cout << "\n";
}

int main(int argc, char **argv)
{
  int r, xc, yc;

  printf("Koordinat titik tengah X Y : "); scanf("%d %d",&xc,&yc);
  printf("Radius Lingkaran           : "); scanf("%d",&r);

  int gd = DETECT;
  int gm = getmaxmode();

  initgraph(&gd, &gm, NULL);

  Circle(xc,yc,r);

  getchar();
  closegraph();

  return 0;
}
