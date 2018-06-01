#include <GL/glut.h>  
#include<iostream>
using namespace std;

int width = 400;
int height = 400;

unsigned char* pixels;

void set_pixel(int x, int y) {
	int pianyi = 200;
	x = x + pianyi;
	y = y + pianyi;
	int index = y*width + x;
	pixels[index * 3 + 0] = 255;
	pixels[index * 3 + 1] = 0;
	pixels[index * 3 + 2] = 0;
}

void set_ellipse_pixel(int x, int y) {
	
	set_pixel(x, y);
	set_pixel(-x, y);
	set_pixel(-x, -y);
	set_pixel(x, -y);
}

void Ellipse_init(int a,int b) {
	int x = 0;
	int y = b;
	int d = b*b + a*a*(0.25 - b);
	set_ellipse_pixel(x, y);
	while (2 * b*b*(x + 1) < 2 * a*a*(y - 0.5)) {
		if (d < 0) {
			x++;
			d += b*b*(2 * x + 3);
		}
		else {
			x++;
			y--;
			d += b*b*(2 * x + 3) + a*a*(2 - 2 * y);
		}
		set_ellipse_pixel(x, y);
	}
	while (y > 0) {
		if (d < 0) {
			y--;
			x++;
			d += b*b*(2 * x + 2) + a*a*(3 - 2 * y);
		}
		else {
			y--;
			d += a*a*(3 - 2 * y);
		}
		set_ellipse_pixel(x, y);
	}
}
void mydraw() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glFlush();
}


int main(int argc, char *argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 100);//
	glutInitWindowSize(width, height);
	glutCreateWindow("ÖÐµã·¨»­ÍÖÔ²");


	pixels = new unsigned char[width*height * 3];
	int a=100, b=60;
	//cout << "ÇëÊäÈë³¤°ëÖáÓë¶Ì°ëÖá£º  ";
	//cin >> a>>b;
	Ellipse_init(a,b);
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	return 0;
}