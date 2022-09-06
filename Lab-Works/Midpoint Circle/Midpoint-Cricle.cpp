#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int r;

void Coordinates(){

    glBegin(GL_LINES);
    glVertex2i(0,200);
    glVertex2i(0,-200);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(200,0);
    glVertex2i(-200,0);
    glEnd();


}


void Display(void){
    int p,x,y;
    x= 0;
    y=r;
    p=1-r;
    Coordinates();

    while(x<=y){
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glVertex2i(y,x);
        glVertex2i(y,-x);
        glVertex2i(x,-y);
        glVertex2i(-x,-y);
        glVertex2i(-y,-x);
        glVertex2i(-y,x);
        glVertex2i(-x,y);
        glEnd();

        x++;
        if (p<0){
                p += 2 * (x + 1) + 1;
        }
        else{
            y--;
            p += 2 * (x + 1) + 1 - 2 * (y - 1);
        }
    }
    glFlush();
}

void init(void){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc,char** argv)
{
    printf("Enter Radius: ");
    scanf("%d",&r);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle ");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
