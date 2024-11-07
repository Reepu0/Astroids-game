#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int FPS = 50;

int start = 0;
int gv = 0;
int level = 0;


int score = 0;


int roadDivTopMost = 0;
int roadDivTop = 0;
int roadDivMdl = 0;
int roadDivBtm = 0;


int lrIndex = 0;


int shape1 = 0;
int lrIndex1 = 0;
int shape2 = +35;
int lrIndex2 = 0;
int shape3 = +70;
int lrIndex3 = 0;

const int font1 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font5 = (int)GLUT_BITMAP_HELVETICA_12;
const int font2 = (int)GLUT_BITMAP_HELVETICA_18;
const int font3 = (int)GLUT_BITMAP_8_BY_13;

char s[30];
void renderBitmapString(float x, float y, void* font, const char* string) {
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void stars() {
    glColor3f(1, 1, 1);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(10, 10);
    glVertex2f(15, 95);
    glVertex2f(20, 16);
    glVertex2f(25, 89);
    glVertex2f(30, 17);
    glVertex2f(35, 75);
    glVertex2f(40, 90);
    glVertex2f(45, 43);
    glVertex2f(50, 90);
    glVertex2f(55, 30);
    glVertex2f(60, 60);
    glVertex2f(65, 50);
    glVertex2f(70, 5);
    glVertex2f(75, 39);
    glVertex2f(80, 20);
    glVertex2f(85, 47);
    glVertex2f(90, 85);
    glVertex2f(73, 2);
    glVertex2f(33, 26);
    glVertex2f(45, 15);
    glVertex2f(11, 39);
    glVertex2f(16, 20);
    glVertex2f(21, 47);
    glVertex2f(10, 12);
    glVertex2f(15, 2);
    glVertex2f(19, 33);
    glVertex2f(33, 32);

    glEnd();
}

void startGame() {

    glColor3f(00, 000, 000);
    glBegin(GL_POLYGON);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();









    char buffer[50];
    glColor3f(1.000, 1.000, 1.000);
    renderBitmapString(80.5, 95, (void*)font3, buffer);

    char buffer1[50];
    glColor3f(1.000, 1.000, 1.000);
    renderBitmapString(80.5, 95 - 2, (void*)font3, buffer1);

    if (score % 50 == 0) {
        int last = score / 50;
        if (last != level) {
            level = score / 50;
            FPS = FPS + 2;

        }
    }
    char level_buffer[50];
    glColor3f(1.000, 1.000, 1.000);
    renderBitmapString(80.5, 95 - 4, (void*)font3, level_buffer);
    stars();


    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 5);
    glVertex2f(lrIndex + 26 - 2, 7);
    glVertex2f(lrIndex + 30 + 2, 7);
    glVertex2f(lrIndex + 30 + 2, 5);
    glEnd();

    glColor3f(1.000, 1.000, 1.000);

    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 1);
    glVertex2f(lrIndex + 26 - 2, 3);
    glVertex2f(lrIndex + 30 + 2, 3);
    glVertex2f(lrIndex + 30 + 2, 1);
    glEnd();

    glColor3f(1.000, 1.000, 000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26, 1);
    glVertex2f(lrIndex + 26, 8);
    glColor3f(1, 0, 0.545);

    glVertex2f(lrIndex + 28, 10);
    glVertex2f(lrIndex + 30, 8);
    glVertex2f(lrIndex + 30, 1);
    glEnd();



    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1 + 26 - 2, shape1 + 100);
    glVertex2f(lrIndex1 + 26 - 2, shape1 + 100 - 2);
    glVertex2f(lrIndex1 + 30 + 2, shape1 + 100 - 2);
    glVertex2f(lrIndex1 + 30 + 2, shape1 + 100);
    glEnd();
    glColor3f(000, 000, 1.123);
    glBegin(GL_POLYGON);
    glColor3f(000, 000, 1.123);
    glVertex2f(lrIndex1 + 26, shape1 + 100);
    glColor3f(000, 1.123, 1.123);
    glVertex2f(lrIndex1 + 26, shape1 + 100 - 7);
    glColor3f(1.123, 000, 1.123);
    glVertex2f(lrIndex1 + 28, shape1 + 100 - 9);
    glVertex2f(lrIndex1 + 30, shape1 + 100 - 7);
    glVertex2f(lrIndex1 + 30, shape1 + 100);
    glEnd();
    shape1--;
    if (shape1 < -100) {
        shape1 = 0;
        lrIndex1 = lrIndex;
    }

    if ((abs(lrIndex - lrIndex1) < 8) && (shape1 + 100 < 10)) {
        start = 0;
        gv = 1;

    }



}

void fristDesign() {



    glColor3f(0.098, 0.098, 0.439);
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();

    glColor3f(00, 0, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 4 + 10);
    glVertex2f(32 - 4, 50 + 4 + 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32 + 45, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 + 45, 50 - 15 + 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 - 14 + 10);
    glVertex2f(32 + 46, 50 - 14 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 - 5, 50 + 5 + 10);
    glVertex2f(32 - 5, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();




    if (gv == 1) {
        glColor3f(1.000, 0.000, 0.000);
        renderBitmapString(35, 60 + 10, (void*)font1, "GAME OVER");
        glColor3f(1.000, 0.000, 0.000);
        char buffer2[50];
        renderBitmapString(33, 60 - 4 + 10, (void*)font1, buffer2);

    }

    glColor3f(0.000, 0.000, 1);
    renderBitmapString(40, 80, (void*)font1, "Asteroids ");
    glColor3f(1, 1, 1);
    renderBitmapString(10, 30, (void*)font1, " # Ahmed Elsayed ");
    renderBitmapString(10, 25, (void*)font1, " # Ahmed saad");
    renderBitmapString(10, 20, (void*)font1, " # Ahmed Atef");
    renderBitmapString(55, 30, (void*)font1, " # Mohamed Elsalal");
    renderBitmapString(55, 25, (void*)font1, " # Abdo Beshary");
    renderBitmapString(55, 20, (void*)font1, " # Ahmed Basry");

    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(30, 50 + 10, (void*)font2, "Press SPACE to START");
    renderBitmapString(30, 50 - 3 + 10, (void*)font2, "Press ESC to Exit");

    glColor3f(1.000, 1.000, 1.000);
    renderBitmapString(30, 50 - 6 + 10, (void*)font3, "Press UP to increase Speed");
    renderBitmapString(30, 50 - 8 + 10, (void*)font3, "Press DWON to decrease Speed");
    renderBitmapString(30, 50 - 10 + 10, (void*)font3, "Press RIGHT to turn Right");
    renderBitmapString(30, 50 - 12 + 10, (void*)font3, "Press LEFT to turn Left");




}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (start == 1) {
        glClearColor(0, 0, 0, 1);
        startGame();
    }

    else {
        fristDesign();
    }



    glFlush();
    glutSwapBuffers();
}



void spe_key(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_DOWN:
        if (FPS > (50 + (level * 2)))
            FPS = FPS - 2;
        break;
    case GLUT_KEY_UP:
        FPS = FPS + 2;
        break;

    case GLUT_KEY_LEFT:
        if (lrIndex >= 0) {
            lrIndex = lrIndex - (FPS / 10);
            if (lrIndex < 0) {
                lrIndex = -1;
            }
        }
        break;


    case GLUT_KEY_RIGHT:
        if (lrIndex <= 44) {
            lrIndex = lrIndex + (FPS / 10);
            if (lrIndex > 44) {
                lrIndex = 45;
            }
        }
        break;

    default:
        break;
    }

}

void processKeys(unsigned char key, int x, int y) {

    switch (key)
    {
    case ' ':
        if (start == 0) {
            start = 1;
            gv = 0;
            FPS = 50;
            roadDivTopMost = 0;
            roadDivTop = 0;
            roadDivMdl = 0;
            roadDivBtm = 0;
            lrIndex = 0;
            shape1 = 0;
            lrIndex1 = 0;
            shape2 = +35;
            lrIndex2 = 0;
            shape3 = +70;
            lrIndex3 = 0;
            score = 0;
            level = 0;
        }
        break;

    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

void timer(int time) {
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, timer, 0);
    printf("%d\n  speeed: ", FPS);
}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 650);
    glutInitWindowPosition(200, 20);
    glutCreateWindow("Asteroids");

    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys);
    glOrtho(0, 100, 0, 100, -1, 1);
    glClearColor(0.184, 0.310, 0.310, 1);
    glutTimerFunc(1000, timer, 0);
    glutMainLoop();

    return 0;
}