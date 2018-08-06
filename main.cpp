#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "figure.h"
#include "park.h"
#include "draw.h"
using namespace std;

void TimeStep(int n) {
    glutTimerFunc(25, TimeStep, 0);     // 40 frames per second
    glutPostRedisplay();
}

void glDraw() {
    static int timer = 0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawPark();     // Draw the frame of the parking lots.
    static Draw d;
    d.drawAll();    // Draw all the moving objects.

    glutSwapBuffers();
    glFlush();
    timer++;        // The variable timer is used to debug... no practical use.
}

int main (int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("VG101 Project 3 Group 14");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 0);
    glutMainLoop();
}