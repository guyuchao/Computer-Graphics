#include <GL/glut.h>  
#include<iostream>
#include"POLYGEN.h"
using namespace std;
#include<map>
#include<set>
#include<queue>

#define WIDTH 400
#define HEIGHT 400

/*global*/
unsigned char* pixels;
map<int, bool> is_edge;
map<int, bool> visited;


int get_pixel_index(point a) {
	return a.y*WIDTH + a.x;
}
void draw_pixel(point a) {
	int pianyi = 200;
	a.x = a.x + pianyi;
	a.y = a.y + pianyi;
	int index = get_pixel_index(a);
	pixels[index * 3 + 0] = 255;
	pixels[index * 3 + 1] = 0;
	pixels[index * 3 + 2] = 0;
}
void draw_pixel_edge(point a) {
	int pianyi = 200;
	a.x = a.x + pianyi;
	a.y = a.y + pianyi;
	int index = get_pixel_index(a);
	pixels[index * 3 + 0] = 0;
	pixels[index * 3 + 1] = 255;
	pixels[index * 3 + 2] = 0;
}


void mydraw() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(WIDTH ,HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glFlush();
}

void fill_pologon_init(){
	queue<point> q;
	polygon p;
	is_edge = p.is_edge;
	q.push(p.seed);
	while (!q.empty()) {
		point tmp = q.front();
		q.pop();
		if (visited.count(get_pixel_index(tmp)) == 0) {
			//未访问
			cout << tmp.x << " " << tmp.y << endl;
			visited[get_pixel_index(tmp)] = 1;
			if (is_edge.count(get_pixel_index(tmp)) == 0) {
				draw_pixel(tmp);
				q.push(point(tmp.x + 1, tmp.y));
				q.push(point(tmp.x - 1, tmp.y));
				q.push(point(tmp.x, tmp.y-1));
				q.push(point(tmp.x, tmp.y+1));
			}
			else {
				draw_pixel_edge(tmp);
			}
		}
	}
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 100);//
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("多边形种子填充");
	pixels = new unsigned char[WIDTH*HEIGHT * 3];	
	fill_pologon_init();
	glutDisplayFunc(&mydraw);
	glutMainLoop();
	system("pause");
	return 0;
}