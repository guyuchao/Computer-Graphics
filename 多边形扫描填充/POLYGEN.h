#pragma once
#ifndef POLYGEN_H
#define POLYGEN_H

#include<vector>
#include<algorithm>
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
	int min_y=10000;
	int max_y = -1;
	polygon() {
		polygen_init();
	}
	void insert_edge(point x, point y) {
		edge_v.push_back(edge(x, y));
		min_y = std::min(std::min(min_y, x.y), y.y);
		max_y = std::max(std::max(max_y, x.y), y.y);
	}
	void polygen_init() {
		
		insert_edge(point(20, 20), point(50, 10));
		insert_edge(point(50, 10), point(110, 30));
		insert_edge(point(110, 30), point(110, 80));
		insert_edge(point(110, 80), point(50, 50));
		insert_edge(point(50, 50), point(20, 70));
		insert_edge(point(20, 70), point(20, 20));
	/*
		insert_edge(point(2, 2), point(5, 1));
		insert_edge(point(5, 1), point(11, 3));
		insert_edge(point(11, 3), point(11, 8));
		insert_edge(point(11, 8), point(5, 5));
		insert_edge(point(5, 5), point(2, 7));
		insert_edge(point(2, 7), point(2, 2));*/
	}
};


#endif // !POLYGEN_H
