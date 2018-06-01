#pragma once
#ifndef AETNET_H_
#define AETNET_H_

#include<set>
#include<map>
#include"POLYGEN.h"
using namespace std;
struct ET_NODE {//新边表节点
	double x_min;
	double delta_x;
	int y_max;
	ET_NODE(int xmin, float d, int ymax) {
		x_min = xmin;//ymin处的x
		delta_x = d;
		y_max = ymax;
	}
};
bool operator<(const ET_NODE x, const ET_NODE y) {
	if (x.x_min != y.x_min)return x.x_min < y.x_min;
	else return x.delta_x < y.delta_x;
}
class NET {
public:
	std::map<int, std::set<ET_NODE>> New_Edge_T;
	void insert(int y_m, ET_NODE tmp) {
		if (New_Edge_T.count(y_m) == 0) {
			std::set<ET_NODE> tmp_v;
			tmp_v.insert(tmp);
			New_Edge_T[y_m] = tmp_v;
		}
		else {
			std::set<ET_NODE> tmp_v = New_Edge_T[y_m];
			tmp_v.insert(tmp);
			New_Edge_T[y_m] = tmp_v;
		}
	}
	NET(polygon p) {
		for (auto &e : p.edge_v) {
			if (e.begin.y < e.end.y) {
				int y_m = e.begin.y;

				ET_NODE tmp(e.begin.x, (e.begin.x - e.end.x)*1.0 / (e.begin.y - e.end.y), e.end.y);
				insert(y_m, tmp);

			}
			else {
				int y_m = e.end.y;

				ET_NODE tmp(e.end.x, (e.begin.x - e.end.x)*1.0 / (e.begin.y - e.end.y), e.begin.y);
				insert(y_m, tmp);

			}
		}
	}
	void transvers() {
		map<int, set<ET_NODE>>::iterator it = New_Edge_T.begin();
		for (it; it != New_Edge_T.end(); it++) {
			cout << it->first << "   ";
			for (auto &i : New_Edge_T[it->first]) {
				cout << "(" << i.x_min << "," << i.delta_x << "," << i.y_max << ")" << "  ";
			}
			cout << endl;
		}
	}
};

class AET {
public:
	std::set<ET_NODE> AET_EDGE_T;
	void insert(ET_NODE e) {
		AET_EDGE_T.insert(e);
	}
};



#endif // !AETNET_H_
