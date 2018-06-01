#include <GL/glut.h>  
#include<iostream>
#include<cmath>
#include"DDL_Line.h"
using namespace std;

unsigned char* pixels = new unsigned char[WIDTH*HEIGHT * 3];;
DDL ddl(pixels);

#define NORTH 8
#define SOUTH 4
#define WEST 2
#define EAST 1

#define X_MIN 100
#define X_MAX 400
#define Y_MIN 100
#define Y_MAX 400

int getCode(point a) {
	int ret_code = 0;
	if (a.x < X_MIN) {
		ret_code += WEST;
	}
	if (a.x > X_MAX) {
		ret_code += EAST;
	}
	if (a.y < Y_MIN) {
		ret_code += SOUTH;
	}
	if (a.y > Y_MAX) {
		ret_code += NORTH;
	}
	return ret_code;
}


void drawLine(point a, point b) {
	//完全可见
	if (getCode(a) == 0 && getCode(b) == 0) {
		ddl.DDL_drawLine(a, b);
		return;
	}
	if ((getCode(a)&getCode(b)) != 0) { return; }//nothing to do
	else {
		if ((getCode(a)&WEST) != 0) {
			int x = X_MIN;
			int y = int(a.y + (x - a.x)*(b.y - a.y)*1.0 / (b.x - a.x));
			drawLine(point(x, y), b);
			return;
		}
		if ((getCode(a)&EAST) != 0) {
			int x = X_MAX;
			int y = int(a.y + (x - a.x)*(b.y - a.y)*1.0 / (b.x - a.x));
			drawLine(point(x, y),b);
			return;
		}
		if ((getCode(a)&SOUTH) != 0) {
			int y = Y_MIN;
			int x = int(a.x + (y - a.y)*(b.x - a.x) *1.0/ (b.y - a.y));
			drawLine(point(x, y), b);
			return;
		}
		if ((getCode(a)&SOUTH) != 0) {
			int y = Y_MAX;
			int x = int(a.x + (y - a.y)*(b.x - a.x) *1.0/ (b.y - a.y));
			drawLine(point(x, y),b);
			return;
		}
		drawLine(b, a);
	}
}











void mydraw() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(WIDTH,HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glFlush();
}


int main(int argc, char *argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 100);//
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("DDL画线");
	

	
	ddl.DDL_drawLine(point(100, 100), point(100, 400));
	ddl.DDL_drawLine(point(400, 100), point(400, 400));
	ddl.DDL_drawLine(point(100, 400), point(400, 400));
	ddl.DDL_drawLine(point(400, 100), point(100, 100));//边界
	drawLine(point(70,60), point(480,420));
	
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	//system("pause");
	return 0;
}