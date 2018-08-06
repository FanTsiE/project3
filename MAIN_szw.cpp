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

void RandomParkingLot(vector<Group*> v,vector<int> space){
    //1:UFO, 2:Rocket, 3:Reserved, 4:Empty
    srand((unsigned int)time(0));
    int flag;
    int car = 0;
    for (int i = 0; i < 10; ++i) {
        flag = rand() % 4 + 1;
        switch(flag){
            case 1:
                v.push_back(new Rocket(i));
                space.push_back(i);
                break;
            case 2:
                v.push_back(new Teleporter(i));
                space.push_back(i);
                break;
            case 3:
                v.push_back(new UFO(i));
                space.push_back(i);
                break;
            case 4:
                if(car == 0){
                    v.push_back(new Car);
                    car++;
                }else{
                    v.push_back(new Rod);}
                space.push_back(i);
                break;
            default:
                break;
        }
    }
    if(car == 0){
        v.pop_back();    //memory is not deleted
        v.push_back(new Car);
    }
    v.push_back(new Rod);   // to make sure there is at least one rod;
}

void glDraw() {
    static int timer = 0;
    static vector<Group*> v;
    static vector<int> space;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPark();

    RandomParkingLot(v,space);
    for (int i = 0; i < 10; ++i) {
        v[i]->draw();
    }//remember to free the memory!!!


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