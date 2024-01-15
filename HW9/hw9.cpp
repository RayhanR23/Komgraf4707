#include <GL/glut.h>
#include <windows.h>

int w = 800, h = 600, x=0,y= 0,z = 0;
int x1 = 0, y1 = 0, z1 = 0, sudut = 0;
int tx = 0, ty = 0,tz=0;

void renderScene(void) {
    static float alpha = 0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);
    glLoadIdentity();

    glTranslatef(tx, ty,tz);         
    glTranslatef(tx, ty,z);         
    glRotatef(sudut, x1, y1, z1);
    glRotatef(alpha, 1, 1, 1);

    glColor3f(1,0, 0);
    alpha = alpha + 0;
    glutWireCube (3);
    glutSolidCube(3);      
    
    glColor3f(1, 0, 0);    
    glutSwapBuffers();
}

void resize(int w1, int h1) {
    glViewport(0, 0, w1, h1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w1 / (float)h1, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Keyboard(GLubyte key, GLint x, GLint y) {

    // translasi
    if (key == 'w' || key == 'W') ty += 1;
    if (key == 's' || key == 'S') ty -= 1;
    if (key == 'a' || key == 'A') tx -= 1;
    if (key == 'd' || key == 'D') tx += 1;
    if (key == 'i' || key == 'I') tz += 1;
    if (key == 'o' || key == 'O') tz -= 1;
    // skala
    if (key == '+')
        //x += 1;
        //y += 1;
        z += 2;
    if (key == '-')
        //x -= 1;
        //y -= 1;
        z -= 2;

    // rotasi
    if (key == 'x' || key == 'X') {
        x1 = 1;
        y1 = 0;
        z1 = 0;
        sudut += 10;
    }
    if (key == 'y' || key == 'Y') {
        x1 = 0;
        y1 = 1;
        z1 = 0;
        sudut += -10;
    }
    if (key == 'z' || key == 'Z') {
        x1 = 0;
        y1 = 0;
        z1 = 1;
        sudut += -10;
    }

    if (key == 'f' || key == 'F') {
        glutFullScreen();
    }

    if (key == 'q' || key == 'Q' || 27 == key) {
        exit(0);
    }
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(1, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(w, h);
    glutCreateWindow("3D");
    gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
    glutDisplayFunc(renderScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(Keyboard);
    glutTimerFunc(1, timer, 0);
    glutMainLoop();
    return 0;
}
