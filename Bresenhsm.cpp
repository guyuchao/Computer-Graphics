#include <GL/glut.h>  
#include<iostream>
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

void Bresenhsm_init(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	float k = dy*1.0/ dx;
	float e = k - 0.5;
	int x = x1;
	int y = y1;
	while (x <= x2) {
		set_pixel(x, y);
		//cout << x << " " << y << endl;
		x++;
		if (e > 0) {
			y++;
			e += k - 1;
		}
		else {
			e += k;
		}
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
	glutCreateWindow("Bresenhsm画线");


	pixels = new unsigned char[width*height * 3];
	int x1, y1, x2, y2;
	cout << "请输入两个点坐标：  ";
	cin >> x1 >> y1 >> x2 >> y2;
	Midpoint_init(x1, y1, x2, y2);
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	return 0;
}