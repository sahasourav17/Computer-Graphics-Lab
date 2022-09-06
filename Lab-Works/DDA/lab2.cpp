#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>

float x1, x2, yy1, y2;

void display() {
    float dy,dx,x,y;

    dx=x2-x1;
    dy=y2-yy1;

    float m = dy/dx;

    if(m<1){
        y = yy1;
        for(x = x1; x<=x2; x++, y+=m){
            glBegin(GL_POINTS);
            glVertex2i(x,ceil(y));
            glEnd();
        }
    }
    else if(m>1){
        x = x1;
        for(y=yy1; y<=y2; y++, x+=(1/m)) {
            glBegin(GL_POINTS);
            glVertex2i(ceil(x),y);
            glEnd();
        }
    }
    else{

        for(y=yy1,x = x1; y<=y2,x <= x2; y++, x++) {
            glBegin(GL_POINTS);
            glVertex2i(ceil(x),y);
            glEnd();
        }
    }


    glFlush();
}

void init(){
    glClearColor(0.7,0.7,0.7,0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
    printf("(x1,y1) : ");
    scanf("%f %f", &x1,&yy1);
    printf("(x2,y2) : ");
    scanf("%f %f", &x2,&y2);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("DDA");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
