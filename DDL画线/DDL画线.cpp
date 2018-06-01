#include <GL/glut.h>  
#include<iostream>
#include<cmath>
#include"DDL_Line.h"
using namespace std;
unsigned char* pixels;
void mydraw() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(WIDTH,HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glFlush();
}
int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 100);//
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("DDL»­Ïß");
	pixels = new unsigned char[WIDTH*HEIGHT * 3];
	DDL ddl(pixels);
	ddl.DDL_drawLine(point(1, 20), point(400, 200));
	glutDisplayFunc(&mydraw);
	glutMainLoop();
	return 0;
}