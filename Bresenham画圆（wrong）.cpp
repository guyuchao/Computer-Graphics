#include <GL/glut.h>  
#include<iostream>
using namespace std;

int width = 400;
int height = 400;

unsigned char* pixels;

void set_pixel(int x, int y) {
	int pianyi = 100;
	x = x + pianyi;
	y = y + pianyi;
	int index = y*width + x;
	pixels[index * 3 + 0] = 255;
	pixels[index * 3 + 1] = 0;
	pixels[index * 3 + 2] = 0;
}

void set_circle_eight_pixel(int x, int y) {
	
	set_pixel(x, y);
	set_pixel(-x, y);
	set_pixel(-x, -y);
	set_pixel(x, -y);
}

void Bresenhamcircle_init(int R) {
	int x = 0;
	int y = R;
	int d = 2 * (1 - R);
	while (y >= 0) {
		int direction;
		set_circle_eight_pixel(x, y);
		if (d < 0) {//D在外面 看h与d哪一个大
			int tmp_d = 2 * d - 2 * y + 1;
			if (tmp_d > 0) {
				direction = 1;
			}
			else {
				direction = 2;
			}
		}
		else if (d > 0) {
			int tmp_d = 2 * d + 2 * x + 1;
			if (tmp_d > 0) {
				direction = 2;
			}
			else {
				direction = 3;
			}
		}
		else {
			direction = 2;
		}
		switch (direction) {
		case 2:
			d += 2*(x - y) + 2;
			y--;
			x++;
			break;
		case 1:
			d += 2 * x + 1;
			x++;
			break;
		case 3:
			d += 1 - 2 * y;
			y--;
			break;
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
	glutCreateWindow("DDL画线");


	pixels = new unsigned char[width*height * 3];
	int R;
	cout << "请输入两个点坐标：  ";
	cin >> R;
	Bresenhamcircle_init(R);
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	return 0;
}