#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>
#include <cmath>
#include <limits>

using namespace std;


float xAwal, yAwal, xEnd, yEnd,xPivot, yPivot;
float sudut;
float nilaiSin,nilaiCos,radian,epsilon;
float xR,yR;
int pilihrefleksi;

void tampilan(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
}

void aturPixel(GLint xCoordinate, GLint yCoordinate, GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}
void translasi (GLint x0, GLint y0, GLint x1, GLint y1)
{
    GLint xgaris=0;
    GLint ygaris=0;
    GLint xmingaris=0;
    GLint ymingaris=0;
    aturPixel(0,0,0,1,0);
    while (xgaris != 200)
    {
        xgaris++;
        aturPixel(xgaris,0,0,1,0);
    }
    while (ygaris != 200)
    {
        ygaris++;
        aturPixel(0,ygaris,0,1,0);
    }
    while (xmingaris != -200)
    {
        xmingaris--;
        aturPixel(xmingaris,0,0,1,0);
    }
    while (ymingaris != -200)
    {
        ymingaris--;
        aturPixel(0,ymingaris,0,1,0);
    }
    aturPixel(x0, y0,1,0,0);
    GLint xAkhir = x0 + x1;
    GLint yAkhir = y0 + y1;
    GLint xtemp= x0;
    GLint ytemp= y0;
    while (xtemp != xAkhir){
        if (xtemp >xAkhir)
        {
            xtemp--;
        }else{
            xtemp++;
        }
        aturPixel(xtemp, ytemp,0,0,0);
    }
    while (ytemp != yAkhir)
    {
        if (ytemp >yAkhir)
        {
            ytemp--;
        }else{
            ytemp++;
        }
        aturPixel(xtemp, ytemp,0,0,0);
    }
    aturPixel(xAkhir, yAkhir,0,0,1);
}

void scalar (GLint x0, GLint y0, GLint sx, GLint sy)
{
    GLint xgaris=0;
    GLint ygaris=0;
    GLint xmingaris=0;
    GLint ymingaris=0;
    aturPixel(0,0,0,1,0);
    while (xgaris != 200)
    {
        xgaris++;
        aturPixel(xgaris,0,0,1,0);
    }
    while (ygaris != 200)
    {
        ygaris++;
        aturPixel(0,ygaris,0,1,0);
    }
    while (xmingaris != -200)
    {
        xmingaris--;
        aturPixel(xmingaris,0,0,1,0);
    }
    while (ymingaris != -200)
    {
        ymingaris--;
        aturPixel(0,ymingaris,0,1,0);
    }
    aturPixel(x0, y0,1,0,0);
    GLint xAkhir = x0 * sx;
    GLint yAkhir = y0 * sy;
    GLint xtemp= x0;
    GLint ytemp= y0;
    while (xtemp != xAkhir){
        if (xtemp >xAkhir)
        {
            xtemp--;
        }else{
            xtemp++;
        }
        aturPixel(xtemp, ytemp,0,0,0);
    }
    while (ytemp != yAkhir)
    {
        if (ytemp >yAkhir)
        {
            ytemp--;
        }else{
            ytemp++;
        }
        aturPixel(xtemp, ytemp,0,0,0);
    }
    aturPixel(xAkhir, yAkhir,0,0,1);
}

void rotation (GLint x0, GLint y0, GLint x1, GLint y1,GLint xp, GLint yp,GLfloat sudut)
{
    GLint xgaris=0;
    GLint ygaris=0;
    GLint xmingaris=0;
    GLint ymingaris=0;
    aturPixel(0,0,0,1,0);
    while (xgaris != 200)
    {
        xgaris++;
        aturPixel(xgaris,0,0,1,0);
    }
    while (ygaris != 200)
    {
        ygaris++;
        aturPixel(0,ygaris,0,1,0);
    }
    while (xmingaris != -200)
    {
        xmingaris--;
        aturPixel(xmingaris,0,0,1,0);
    }
    while (ymingaris != -200)
    {
        ymingaris--;
        aturPixel(0,ymingaris,0,1,0);
    }
    aturPixel(x0, y0 , 1,0,0);
    GLint xtemp,ytemp,xtemp2,ytemp2,xAkhir,yAkhir;
    xtemp = x0;
    ytemp = y0;
    radian = sudut * M_PI / 180;
    if (0 < sudut && sudut <= 90) {
        nilaiSin = sin(radian);
        nilaiCos = cos(radian);
    }
    else if (90 < sudut && sudut <= 180) {
        nilaiSin = sin(radian);
        nilaiCos = -cos(radian);
    }
    else if (180 < sudut && sudut <= 270) {
        nilaiSin = -sin(radian);
        nilaiCos = -cos(radian);
    }
    else if (270 < sudut && sudut <= 360) {
        nilaiSin = -sin(radian);
        nilaiCos = cos(radian);
    }
    epsilon = numeric_limits<float>::epsilon();
    if (fabs(nilaiCos) < epsilon) {
        nilaiCos = 0;
    }else if (fabs(nilaiSin) < epsilon) {
        nilaiSin = 0;
    }    
    while (xtemp != x1 || ytemp != y1)
    {
        if ( xtemp < x1)
        {
            xtemp++;
        }
        else if ( xtemp > x1)
        {
            xtemp--;
        }
        if ( ytemp < y1)
        {
            ytemp++;
        }
        else if ( ytemp > y1)
        {
            ytemp--;
        }
        aturPixel(xtemp, ytemp,0,0,0);
    }

    if (xp == x0 && yp == y0){
        xtemp2=x0; 
        ytemp2=y0;        
        xAkhir = xp + ((x1 - xp) * nilaiCos) - ((y1 - yp) * nilaiSin);
        yAkhir = yp + ((x1 - xp) * nilaiSin) + ((y1 - yp) * nilaiCos);        
        
        while (xtemp2 != xAkhir || ytemp2 != yAkhir)
        {
            if ( xtemp2 < xAkhir)
            {
                xtemp2++;
            }
            else if ( xtemp2 > xAkhir)
            {
                xtemp2--;
            }
            if ( ytemp2 < yAkhir)
            {
                ytemp2++;
            }
            else if ( ytemp > yAkhir)
            {
                ytemp2--;
            }
            aturPixel(xtemp2, ytemp2,1,0,1);
        }
        aturPixel(xAkhir, yAkhir,0,0,1);
    }else if (xPivot == x1 && yPivot == y1){
        xtemp2=x1; 
        ytemp2=y1;        
        xAkhir = xp + ((x0 - xp) * nilaiCos) - ((y0 - yp) * nilaiSin);
        yAkhir = yp + ((x0 - xp) * nilaiSin) + ((y0 - yp) * nilaiCos);        
        
        while (xtemp2 != xAkhir || ytemp2 != yAkhir)
        {
            if ( xtemp2 < xAkhir)
            {
                xtemp2++;
            }
            else if ( xtemp2 > xAkhir)
            {
                xtemp2--;
            }
            if ( ytemp2 < yAkhir)
            {
                ytemp2++;
            }
            else if ( ytemp > yAkhir)
            {
                ytemp2--;
            }
            aturPixel(xtemp2, ytemp2,1,0,1);
        }
        aturPixel(xAkhir, yAkhir,1,0,0);
    }    
    aturPixel(x1,y1,0,0,1);
}
void bresenham(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
{
    GLint xgaris=0;
    GLint ygaris=0;
    GLint xmingaris=0;
    GLint ymingaris=0;
    aturPixel(0,0,0,1,0);
    while (xgaris != 200)
    {
        xgaris++;
        aturPixel(xgaris,0,0,1,0);
    }
    while (ygaris != 200)
    {
        ygaris++;
        aturPixel(0,ygaris,0,1,0);
    }
    while (xmingaris != -200)
    {
        xmingaris--;
        aturPixel(xmingaris,0,0,1,0);
    }
    while (ymingaris != -200)
    {
        ymingaris--;
        aturPixel(0,ymingaris,0,1,0);
    }
    aturPixel(x0,y0,1,0,0);    
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
        
    
    aturPixel(xEnd, yEnd,0,0,1);
}

void dda(GLfloat x0, GLfloat y0, GLfloat xA, GLfloat yA)
{   
    GLint xgaris=0;
    GLint ygaris=0;
    GLint xmingaris=0;
    GLint ymingaris=0;
    aturPixel(0,0,0,1,0);
    while (xgaris != 200)
    {
        xgaris++;
        aturPixel(xgaris,0,0,1,0);
    }
    while (ygaris != 200)
    {
        ygaris++;
        aturPixel(0,ygaris,0,1,0);
    }
    while (xmingaris != -200)
    {
        xmingaris--;
        aturPixel(xmingaris,0,0,1,0);
    }
    while (ymingaris != -200)
    {
        ymingaris--;
        aturPixel(0,ymingaris,0,1,0);
    } 
    aturPixel(x0,y0,1,0,0);
    GLfloat dx;
    GLfloat dy;
    GLfloat xR,yR;
    GLfloat r;
    GLfloat xtemp = x0;    
    GLfloat ytemp = y0;
    dx= xA - x0;
    dy= yA - y0;    
    if (abs(dy) > abs (dx) )
    {
        r =abs(dy);
    }else if (abs(dx) > abs (dy))
    {
        r = abs(dx);
    }

    xR = dx/r;
    yR = dy/r;
    
    GLint i = 0;
    while (i < r)
    {
        x0 = x0 + xR;        
        y0 = y0 + yR;
        xtemp = round(x0);        
        ytemp = round(y0);
        i++;
        aturPixel(xtemp,ytemp,0,0,0);    
    }    
    aturPixel(xA,yA,0,0,1);
}

void refleksi(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat xR,GLfloat yR,GLint refleksi)  
{
    GLint xgaris=0;
    GLint ygaris=0;
    GLint xmingaris=0;
    GLint ymingaris=0;
    aturPixel(0,0,0,1,0);
    while (xgaris != 200)
    {
        xgaris++;
        aturPixel(xgaris,0,0,1,0);
    }
    while (ygaris != 200)
    {
        ygaris++;
        aturPixel(0,ygaris,0,1,0);
    }
    while (xmingaris != -200)
    {
        xmingaris--;
        aturPixel(xmingaris,0,0,1,0);
    }
    while (ymingaris != -200)
    {
        ymingaris--;
        aturPixel(0,ymingaris,0,1,0);
    } 
    aturPixel(x0,y0,1,0,0); 
    GLint xtemp,ytemp,xtemp2,ytemp2,xAkhir1,yAkhir1,xAkhir2,yAkhir2;
    xtemp = x0; 
    ytemp = y0;

     while (xtemp != x1 || ytemp != y1)
    {
        if ( xtemp < x1)
        {
            xtemp++;
        }
        else if ( xtemp > x1)
        {
            xtemp--;
        }
        if ( ytemp < y1)
        {
            ytemp++;
        }
        else if ( ytemp > y1)
        {
            ytemp--;
        }
        aturPixel(xtemp, ytemp,0,0,0);
    }
    
    if (refleksi == 1)
    {
        xAkhir1 = x0 * xR;
        yAkhir1 = y0 * yR;
        xAkhir2 = x1 * xR;
        yAkhir2 = y1 * yR;
    }else if ( refleksi == 2)
    {
        xAkhir1 = x0 * xR;
        yAkhir1 = y0 * yR;
        xAkhir2 = x1 * xR;
        yAkhir2 = y1 * yR;
    }else if ( refleksi == 3)
    {
        xAkhir1 = x0 * xR;
        yAkhir1 = y0 * yR;
        xAkhir2 = x1 * xR;
        yAkhir2 = y1 * yR;
    }else if ( refleksi == 4)
    {
        xAkhir1 = y0;        
        yAkhir1 = x0;
        xAkhir2 = y1;
        yAkhir2 = x1;        
    }
    xtemp2 = xAkhir1;
    ytemp2 = yAkhir1;
    aturPixel(xAkhir1, yAkhir1,1,0,0);
    while (xtemp2 != xAkhir2 || ytemp2 != yAkhir2)
    {
        if ( xtemp2 < xAkhir2)
        {
            xtemp2++;
        }
        else if ( xtemp > xAkhir2)
        {
            xtemp2--;
        }
        if ( ytemp2 < yAkhir2)
        {
            ytemp2++;
        }
        else if ( ytemp2 > yAkhir2)
        {
            ytemp2--;
        }
        aturPixel(xtemp2, ytemp2,1,0,1);
    }    
    aturPixel(x1, y1,0,0,1);    
    aturPixel(xAkhir2, yAkhir2,0,0,1);
}

void gambarTranslasi(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);    
    translasi(xAwal, yAwal, xEnd, yEnd);    
}

void gambarScalar(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);    
    scalar(xAwal, yAwal, xEnd, yEnd);    
}

void gambarRotation(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);            
    rotation(xAwal,yAwal,xEnd,yEnd,xPivot,yPivot,sudut);
}

void gambarBresenham (void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);            
    bresenham(xAwal, yAwal, xEnd, yEnd);
}

void gambarDDA (void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);            
    dda(xAwal, yAwal, xEnd, yEnd);
}

void gambarRefleksi (void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);            
    refleksi(xAwal, yAwal, xEnd, yEnd,xR,yR,pilihrefleksi);
}

int main(int argc, char** argv) {
    int pilih;
    int pilihPivot;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("UTS Komputer Grafik");
    tampilan();

    cout << ("1.Translasi \n2.Scalar \n3.Rotation \n4.Bresenham \n5.DDA \n6.Refleksi \nPilih salah satu dari rumus diatas :")<<endl;
    cin >> pilih;    
    switch(pilih) {
        case 1:
            cout << ("Masukkan koordinat titik awal (x0 y0): ");
            cin >> xAwal;
            cin >> yAwal;
            cout << ("Masukkan titik geser (x1 y1): ");
	        cin >> xEnd;
            cin >> yEnd;
            glutDisplayFunc(gambarTranslasi);            
            glutMainLoop();
            break;
        case 2:
            cout << ("Masukkan koordinat titik awal (x0 y0): ");
            cin >> xAwal;
            cin >> yAwal;
            cout << ("Masukkan titik skala (x1 y1): ");
	        cin >> xEnd;
            cin >> yEnd;
            glutDisplayFunc(gambarScalar);            
            glutMainLoop();
            break;
        case 3:
            cout << ("Masukkan koordinat titik awal (x0 y0): ");
            cin >> xAwal;
            cin >> yAwal;
            cout << ("Masukkan koordinat titik akhir  (x1 y1): ");
	        cin >> xEnd;
            cin >> yEnd;
            cout << ("pilih pivot:\n1.titik awal\n2.titik akhir\n");        
            cin >> pilihPivot;                        
            switch (pilihPivot)
            {
            case 1:
                xPivot=xAwal;
                yPivot=yAwal;                
                break;
            
            case 2:
                xPivot=xEnd;
                yPivot=yEnd;                
                break;

            default:
                printf("Pilihan tidak valid.\n");
                return 1;
            }         
            cout << ("Masukkan besar sudut: ");
            cin >> sudut;
            glutDisplayFunc(gambarRotation);            
            glutMainLoop();
            break;
        case 4:
            cout << ("Masukkan koordinat titik awal (x0 y0): ");
            cin >> xAwal;
            cin >> yAwal;
            cout << ("Masukkan titik akhir (x1 y1): ");
            cin >> xEnd;
            cin >> yEnd;
            glutDisplayFunc(gambarBresenham);            
            glutMainLoop();
            break;
        case 5:
            cout << ("Masukkan koordinat titik awal (x0 y0): ");
            cin >> xAwal;
            cin >> yAwal;
            cout << ("Masukkan titik akhir (x1 y1): ");
            cin >> xEnd;
            cin >> yEnd;
            glutDisplayFunc(gambarDDA);            
            glutMainLoop();
            break;
        case 6:
            cout << ("Masukkan koordinat titik awal (x0 y0): ");
            cin >> xAwal;
            cin >> yAwal;
            cout << ("Masukkan titik akhir (x1 y1): ");
            cin >> xEnd;
            cin >> yEnd;
            cout << "Piliih refleksi yang diinginkan: \n1.Refleksi Terhadap Sumbu X\n2.Refleksi Terhadap Sumbu Y\n3.Refleksi Terhadap Sumbu Tegak Lurus Bidang XY\n4.Refleksi Terhadap Garis Diagonal Y=X\n";
            cin >> pilihrefleksi;
            switch (pilihrefleksi)
            {
                case 1:   
                    xR = 1;
                    yR = -1;                 
                    break;

                case 2:
                    xR = -1;
                    yR = 1;                 
                    break;

                case 3:
                    xR = -1;
                    yR = -1;                 
                    break;

                case 4:
                    xR = 1;
                    yR = 1;                 
                    break;

                default:
                    printf("Pilihan tidak valid.\n");
                    return 1;
            }
            glutDisplayFunc(gambarRefleksi);            
            glutMainLoop();
            break;
        default:
            printf("Pilihan tidak valid.\n");
            return 1;
    }    
    return 0;
}
