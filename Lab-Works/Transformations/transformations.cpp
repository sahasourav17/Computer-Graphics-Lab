#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, choice = 0, edges = 3;

vector<int> pntX;
vector<int> pntY;

int transX, transY;
double scaleX, scaleY;
double angle, angleRad;

double round(double d){
	return floor(d + 0.5);
}

void draw_triangle(){
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++){
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
}


void translate_triangle(int x, int y){
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++){
		glVertex2i(pntX[i] + x, pntY[i] + y);
	}
	glEnd();
}

void scale_triangle(double x, double y){
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++){
		glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
	}
	glEnd();
}

void rotate_triangle(double angleRad){
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++){
		glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
	}
	glEnd();
}


void myInit(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	if (choice == 1){
		draw_triangle();
		translate_triangle(transX, transY);
	}
	else if (choice == 2){
		draw_triangle();
		scale_triangle(scaleX, scaleY);
	}
	else if (choice == 3){
		draw_triangle();
		rotate_triangle(angleRad);
	}
	glFlush();
}

int main(int argc, char** argv)
{
    int x1,y1,x2,y2,x3,y3;
    cout<<"Enter 3 points (xi,yi): "<<endl;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    pntX.push_back(x1);
	pntX.push_back(x2);
	pntX.push_back(x3);
	pntY.push_back(y1);
	pntY.push_back(y2);
	pntY.push_back(y3);

    cout<<endl;
    cout << "1. Translation" << endl;
	cout << "2. Scaling" << endl;
	cout << "3. Rotation" << endl;
	cout << "Enter choice: ";

	cin >> choice;

	if (choice == 1){
		cout << "Enter Tx and Ty: ";
		cin >> transX >> transY;
        glTranslatef(transX, transY, 0.0);
	}
	else if (choice == 2){
		cout << "Enter  Sx and Sy: ";
		cin >> scaleX >> scaleY;
	}
	else if (choice == 3){
		cout << "Enter the rotation angle: ";
		cin >> angle;
		angleRad = angle * 3.1416 / 180;
        glRotatef(angleRad, 0, 0, 1);
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Transformations");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

}