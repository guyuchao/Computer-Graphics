#pragma once
#ifndef POLYGEN_H
#define POLYGEN_H

const int W = 400;
#include<vector>
#include<algorithm>
#include<map>
struct point {
	int x;
	int y;
	point() {}
	point(int a, int b) {
		x = a;
		y = b;
	}
};
struct edge {
	point begin;
	point end;
	edge(point x, point y) {
		begin = x;
		end = y;
	}
};
class polygon {
public:
	std::vector<edge> edge_v;
	std::map<int, bool> is_edge;
	point seed;
	polygon() {
		polygen_init();
		seed = point(40, 50);

	}
	void insert_edge(point x, point y) {
		DDL_init(x.x,x.y, y.x,y.y);
	}
	void DDL_init_x(int x1, int y1, int x2, int y2) {
		int index;
		double k = (y2 - y1) *1.0 / (x2 - x1);
		double now_y = y1;
		for (int x = x1; x <= x2; x++) {
			int y = int(now_y + 0.5);
			index = y*W + x;
			is_edge[index] = 1;
			now_y += k;
		}

	}
	void DDL_init_y(int x1, int y1, int x2, int y2) {
		int index;
		double k = (x2 - x1) *1.0 / (y2 - y1);
		double now_x = x1;
		for (int y = y1; y <= y2; y++) {
			int x = int(now_x + 0.5);
			index = y*W + x;
			is_edge[index] = 1;
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
	void polygen_init() {
		insert_edge(point(20, 20), point(50, 10));
		insert_edge(point(50, 10), point(110, 30));
		insert_edge(point(110, 30), point(110, 80));
		insert_edge(point(110, 80), point(50, 50));
		insert_edge(point(50, 50), point(20, 70));
		insert_edge(point(20, 70), point(20, 20));
	}
};


#endif // !POLYGEN_H
