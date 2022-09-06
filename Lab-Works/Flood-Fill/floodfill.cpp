#include<bits/stdc++.h>
#include <GL/glut.h>

int ww = 700, wh = 500;
float oldCol[3] = {1.0, 1.0, 0.0};
float fillCol[3] = {1.0, 0.0, 0.0};

void setPixel(int pointx, int pointy, float f[3])
{
     glBegin(GL_POINTS);
     glColor3fv(f);
     glVertex2i(pointx, pointy);
     glEnd();
     glFlush();
}

void getPixel(int x, int y, float pixels[3])
{
   glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);
}

void drawTriangle(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(360.0, 280.0);
    glVertex2f(280.0, 220.0);
    glVertex2f(350.0, 220.0);

    glEnd();
}

void display()
{
     glClearColor(1.0, 1.0, 1.0, 1.0);
     glClear(GL_COLOR_BUFFER_BIT);
     drawTriangle();
     glFlush();
}

void floodfill4(int x,int y,float oldcolor[3],float newcolor[3])
{
    float color[3];
    getPixel(x,y,color);
    if(color[0]==oldcolor[0] && (color[1])==oldcolor[1] && (color[2])==oldcolor[2])
    {
          setPixel(x, y, newcolor);
          floodfill4(x+1, y, oldcolor, newcolor);
          floodfill4(x+1, y+1, oldcolor,newcolor);
          floodfill4(x-1, y, oldcolor,newcolor);
          floodfill4(x-1, y+1, oldcolor,newcolor);
          floodfill4(x, y+1, oldcolor,newcolor);
          floodfill4(x-1, y-1, oldcolor,newcolor);
          floodfill4(x, y-1, oldcolor,newcolor);
          floodfill4(x+1, y-1, oldcolor,newcolor);
     }
}

void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
         int xi = x;
         int yi = (wh-y);
         floodfill4(xi, yi, oldCol, fillCol);
     }
}

void init()
{
    glViewport(0, 0, ww, wh);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)ww, 0.0,(GLdouble)wh);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(ww,wh);
     glutCreateWindow("Flood-Fill");
     glutDisplayFunc(display);
     init();
     glutMouseFunc(mouse);
     glutMainLoop();

     return 0;
}
