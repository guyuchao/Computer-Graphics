#include <GL/glut.h>  
#include<iostream>
#include<cmath>
using namespace std;

int width = 200;
int height = 200;

unsigned char* pixels;

void set_pixel(int x, int y) {
	int index = y*width + x;
	pixels[index * 3 + 0] = 255;
	pixels[index * 3 + 1] = 0;
	pixels[index * 3 + 2] = 0;
}

void mydraw() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glFlush();
}
class point {
public:
	double x, y;
	point(double xx, double yy) {
		x = xx;
		y = yy;
	}
	point() {
		x = 0;
		y = 0;
	}
	friend point operator *(double b,const point a);
	friend point operator +(const point a, const point b);
};
point operator +(const point a, const point b) {
	return point(a.x + b.x, a.y + b.y);
}
point operator *(double b,const point a) {
	return point(b*a.x, b*a.y);
}
void bezier() {
	cout << "请输入6阶bezier曲线控制点";
	point p[6];
	for (int i = 1; i <= 6; i++) {
		cout << "请输入第i个控制点坐标:" << endl;
		cin >> p[i-1].x >> p[i-1].y;
	}
	int a[6] = { 1,5,10,10,5,1 };
	int b[6] = {5,4,3,2,1,0 };
	int c[6] = { 0,1,2,3,4,5 };
	for (int j = 0; j < 1000; j++) {
		double t = j*1.0 / 1000;
		point tmp;
		for (int i = 0; i < 6; i++) {
			tmp =tmp+ a[i] * pow(1 - t, b[i])*pow(t, c[i])*p[i];
		}
		set_pixel(int(tmp.x),int(tmp.y));
	}
	/*
	10 20
	40 70
	80 130
	100 20
	120 10
	160 15
	*/
}
int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 100);//
	glutInitWindowSize(width, height);
	glutCreateWindow("bezier曲线");


	pixels = new unsigned char[width*height * 3];
	bezier();
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	return 0;
}