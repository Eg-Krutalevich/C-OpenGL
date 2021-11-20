#include <GL/glut.h> 
void init(void) {
    glClearColor(0.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-0.5, 0.5, -0.5, 0.5);
}
void rhombus(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, 0.0f);
    glEnd();
    glFlush();
}
void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 100);
    glutInitWindowSize(40, 70);
    glutCreateWindow("Rombus");
    init();
    glutDisplayFunc(rhombus);
    glutMainLoop();
}
