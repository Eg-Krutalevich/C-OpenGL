#include <Windows.h>
#include <tchar.h>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glut32.lib")
#include "glut.h"
#include <stdlib.h>
#include <cmath>
#include <iostream>
using namespace std;

void init(void) {
	glClearColor(0, 0, 0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-20, 20.0, -20.0, 20.0);
}
void setPixel(int x, int y) {
	glPointSize(2.5);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void linex(int x0, int y0, int xe, int ye) {
	int dx = abs(x0 - xe), dy = abs(y0 - ye);
	if (xe < x0) {
		int buff = x0;
		x0 = xe;
		xe = buff;
		buff = y0;
		y0 = ye;
		ye = buff;
	}
	int x = x0, y = y0, p = 2 * dy - dx;
	setPixel(x, y);
	while (x < xe) {
		x++;
		if (p < 0) {
			p += 2 * dy;
		}
		else {
			if (y0 < ye) {
				y++;
			}
			else {
				y--;
			}
			p += 2 * dy - 2 * dx;
		}
		setPixel(x, y);
	}
}
void liney(int x0, int y0, int xe, int ye) {
	int dx = abs(x0 - xe), dy = abs(y0 - ye);
	if (ye < y0) {
		int buff = x0;
		x0 = xe;
		xe = buff;
		buff = y0;
		y0 = ye;
		ye = buff;
	}
	int x = x0, y = y0, p = 2 * dx - dy;
	setPixel(x, y);
	while (y < ye) {
		y++;
		if (p < 0) {
			p += 2 * dx;
		}
		else {
			if (x0 < xe) {
				x++;
			}
			else {
				x--;
			}
			p += 2 * dx - 2 * dy;
		}
		setPixel(x, y);
	}
}
void lines(int x0, int y0, int xe, int ye) {
	int dx = xe - x0, dy = ye - y0;
	abs(dx) > abs(dy) ? linex(x0, y0, xe, ye) : liney(x0, y0, xe, ye);
}
void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.7);
	lines(0, 0, 3, 10);
	lines(0, 0, 10, 3);
	glColor3f(0.3, 0.3, 0.7);
	lines(0, 0, -3, 10);
	lines(0, 0, -10, 3);
	glColor3f(0.0, 0.0, 0.7);
	lines(0, 0, -3, -10);
	lines(0, 0, -10, -3);
	glColor3f(0.5, 0.8, 0.3);
	lines(0, 0, 3, -10);
	lines(0, 0, 10, -3);
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200, 0);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Brezenhem");
	init();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
