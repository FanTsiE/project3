#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include "figure.h"
#include "park.h"
using namespace std;

void TimeStep(int n) {
    glutTimerFunc(25, TimeStep, 0);
    glutPostRedisplay();
}

void glDraw() {
    static int timer = 0;
    static vector<Group*> v;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPark();

    v.push_back(new Rocket(7));
    v[0]->draw();
    v.push_back(new Teleporter(2));
    v[1]->draw();
    v.push_back(new UFO(0));
    v[2]->draw();
    v.push_back(new Rod);
    v[3]->draw();
    v.push_back(new Car);
    v[4]->draw();   //remember to free the memory!!!

    glutSwapBuffers();
    glFlush();
    timer++; //std::cout << timer << std::endl;
}

int main (int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Home sweet home");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 0);
    glutMainLoop();
}