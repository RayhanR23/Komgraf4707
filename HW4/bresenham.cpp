#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>

float xAwal, yAwal, xEnd, yEnd;

void tampilan(void) {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50);
}

void titikAwal(GLint xCoordinate, GLint yCoordinate,GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}
void aturPixel(GLint xCoordinate, GLint yCoordinate,GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void aturPixelAkhir(GLint xCoordinate, GLint yCoordinate, GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void aturPixelAwal(GLint xCoordinate, GLint yCoordinate, GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void garisBresenham(GLint x0, GLint y0, GLint xEnd, GLint yEnd) {
    titikAwal(0,0,0,1,0);    
    aturPixelAwal(x0,y0,1,0,0);    
    GLint dx = (float) fabs((float) xEnd - x0);
    GLint dy = (float) fabs((float) yEnd - y0);
    GLint p = 2 * dy - dx;
    GLint twoDy = 2 * dy;
    GLint twoDyMinusDx = 2 * (dy - dx);
    GLint x, y;

    if (x0 < xEnd && y0 < yEnd) {
        x = x0;
        y = y0;        
        while (x < xEnd) {
        x++;
        if (p < 0)
            p += twoDy;
        else {
            y++;
            p += twoDyMinusDx;
        }
        aturPixel(x, y,0,0,0);
        }
    }else if (x0 > xEnd && y0 < yEnd) {
        x = x0;
        y = y0;      
        while (x > xEnd) {
            x--;
            if (p < 0)
                p += twoDy;
            else {
                y++;
                p += twoDyMinusDx;
            }
            aturPixel(x, y,0,0,0);
        }
        
    }else if (x0 < xEnd && y0 > yEnd) {
        x = x0;
        y = y0;        
        while (x < xEnd) {
            x++;
            if (p < 0)
                p += twoDy;
            else {
                y--;
                p += twoDyMinusDx;
            }
            aturPixel(x, y,0,0,0);
        }
        
    }else if (x0 > xEnd && y0 > yEnd) {
        x = x0;
        y = y0;        
        while (x > xEnd) {
            x--;
            if (p < 0)
                p += twoDy;
            else {
                y--;
                p += twoDyMinusDx;
            }
            aturPixel(x, y,0,0,0);
        }
        
    }
        
    
    aturPixelAkhir(xEnd, yEnd,0,0,1);
}

void gambarGaris(void) {
    glClear(GL_COLOR_BUFFER_BIT);    
    glPointSize(2.0);
    
    /*xAwal *= 10;
    yAwal *= 10;
    xEnd *= 10;
    yEnd *= 10;
    */

    garisBresenham(xAwal, yAwal, xEnd, yEnd);
}

int main(int argc, char** argv) {
     glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Garis Bresenham");
    tampilan();

    printf("Masukkan koordinat titik awal (x0 y0): ");
    scanf("%f %f", &xAwal, &yAwal);
    printf("Masukkan koordinat titik akhir (xEnd yEnd): ");
    scanf("%f %f", &xEnd, &yEnd);

    glutDisplayFunc(gambarGaris);
    glutMainLoop();
    return 0;
}
