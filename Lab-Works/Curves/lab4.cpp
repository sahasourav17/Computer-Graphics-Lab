#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159

void C_curve(float x, float y, float len, float alpha,int n){

    if(n>0){
        len = len/sqrt(2.0);
        C_curve(x,y,len,alpha+(45*PI)/180,n-1);
        x = x + len*cos(alpha+(45*PI)/180);
        y = y + len*sin(alpha+(45*PI)/180);
        C_curve(x,y,len,alpha-(45*PI)/180,n-1);
    }
    else{
        glBegin(GL_LINES);
        glVertex2f(x,y);
        glVertex2f(x+len*cos(alpha),y+len*sin(alpha));
    }
    glEnd();
    glFlush();
}

void Koch_curve(float x,float y,float len,float alpha,int n){
    glBegin(GL_LINES);
    if(n>0){
        len = len/3;
        Koch_curve(x,y,len,alpha,n-1);
        x = x + len*cos(alpha);
        y = y + len*sin(alpha);

        Koch_curve(x,y,len,alpha-(60 * PI)/ 180,n-1);
        x = x + len*cos(alpha-(60 * PI)/ 180);
        y = y + len*sin(alpha-(60 * PI)/ 180);

        Koch_curve(x,y,len,alpha+(60 * PI)/ 180,n-1);
        x = x + len*cos(alpha+(60 * PI)/ 180);
        y = y + len*sin(alpha+(60 * PI)/ 180);
        Koch_curve(x,y,len,alpha,n-1);
    }
    else{
        glVertex2f(x,y);
        glVertex2f(x+len*cos(alpha),y+len*sin(alpha));
    }
    glEnd();
    glFlush();
}

void S_gasket(float x1,float y1,float x2,float y2,float x3,float y3,int n){
    glBegin(GL_TRIANGLES);

    float x12,y12,x13,y13,x23,y23;
    if(n>0){
        x12 = (x1+x2)/2;
        y12 = (y1+y2)/2;
        x13 = (x1+x3)/2;
        y13 = (y1+y3)/2;
        x23 = (x2+x3)/2;
        y23 = (y2+y3)/2;
        S_gasket(x1,y1,x12,y12,x13,y13,n-1);
        S_gasket(x12,y12,x2,y2,x23,y23,n-1);
        S_gasket(x13,y13,x23,y23,x3,y3,n-1);
    }
    else{
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
    }
    glEnd();
    glFlush();
}


void display(void){
    C_curve(0,0,40,((90*PI)/180),10);
    // Koch_curve(50,-50,100,((180 * PI)/180),8);
    // S_gasket(0,0,70,0,35,-35,5);
}

void init(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(480,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("C-Curve");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
