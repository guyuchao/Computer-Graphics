#pragma once
#ifndef DDL_Line_H_
#define DDL_Line_H_
#define WIDTH 500
#define HEIGHT 500
#include<cmath>
struct point {
	int x;
	int y;
	point() {}
	point(int a, int b) {
		x = a;
		y = b;
	}
};
class DDL {
private:
	unsigned char* pixels;
	void set_pixel(int x, int y) {
		int index = y*WIDTH + x;
		pixels[index * 3 + 0] = 255;
		pixels[index * 3 + 1] = 0;
		pixels[index * 3 + 2] = 0;
	}
	void DDL_init_x(int x1, int y1, int x2, int y2) {
		int index;
		double k = (y2 - y1) *1.0 / (x2 - x1);
		double now_y = y1;
		for (int x = x1; x <= x2; x++) {
			int y = int(now_y + 0.5);
			set_pixel(x, y);
			now_y += k;
		}

	}
	void DDL_init_y(int x1, int y1, int x2, int y2) {
		int index;
		double k = (x2 - x1) *1.0 / (y2 - y1);
		double now_x = x1;
		for (int y = y1; y <= y2; y++) {
			int x = int(now_x + 0.5);
			set_pixel(x, y);
			now_x += k;
		}
	}
	void DDL_init(int x1, int y1, int x2, int y2) {
		double k = (y2 - y1) *1.0 / (x2 - x1);
		if (fabs(k) <= 1) {
			if (x1 < x2) {
				DDL_init_x(x1, y1, x2, y2);
			}
			else {
				DDL_init_x(x2, y2, x1, y1);
			}
		}
		else {
			if (y1 < y2) {
				DDL_init_y(x1, y1, x2, y2);
			}
			else {
				DDL_init_y(x2, y2, x1, y1);
			}
		}
	}
public:
	DDL(unsigned char* &p) {
		pixels = p;
	}
	void DDL_drawLine(point x, point y) {
		DDL_init(x.x, x.y, y.x, y.y);
	}
};
#endif // !DDL_Line_H_
