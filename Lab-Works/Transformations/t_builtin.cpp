#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

const double pi = acos(-1.0);
int choice;
double X1, Y1, X2, Y2, X3, Y3;
double tx, ty, angle, sx, sy;

struct Point {
	GLint x;
	GLint y;
};

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

void init() {
	glClearColor(0,0, 0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void translate(double& x, double& y, double tx, double ty) {
    x += tx;
    y += ty;
}

void rot(double& x, double& y, double angle) {
    double rad = (angle * pi) / 180.0;
    double x1 = x * cos(rad) - y * sin(rad);
    double y1 = x * sin(rad) + y * cos(rad);

    x = x1, y = y1;
}

void scale(double& x, double& y, double sx, double sy) {
    x *= sx;
    y *= sy;
}

void draw_triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    glBegin(GL_TRIANGLES);

    glColor3f(1,1,1);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}

void display(void) {
    glClearColor(0,0, 0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    draw_triangle(X1, Y1, X2, Y2, X3, Y3);

	if (choice == 1) {
        glTranslatef(tx, ty, 0.0);
	} else if (choice == 2) {
        glRotatef(angle, 0, 0, 1);
	} else {
        scale(X1, Y1, sx, sy);
        scale(X2, Y2, sx, sy);
        scale(X3, Y3, sx, sy);


	}

    draw_triangle(X1, Y1, X2, Y2, X3, Y3);
//	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter triangle co-ordinates { x1 y1 x2 y2 x3 y3}: ";
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;

    cout << "Choose 1:translate 2:rotate 3:scale ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter tx ty: ";
        cin >> tx >> ty;
    } else if (choice == 2) {
        cout << "Enter angle in degree: ";
        cin >> angle;
    } else {
        cout << "Enter sx sy: ";
        cin >> sx >> sy;
    }

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1024, 680);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Open GL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}