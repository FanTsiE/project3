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
    auto *space=new int [10];
   for (int i=0;i<=9;i++)*(space+i)=0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPark();
    v.push_back(new Rocket(7));
    *(space+7)=1;
    v[0]->draw(0);
    v.push_back(new Teleporter(2));
    *(space+2)=1;//The space of car is different from that of the others', so use (space+5/-5) of others
    v[1]->draw(0);
    v.push_back(new UFO(5));
    v[2]->draw(0);
    *(space+5)=1;
    v.push_back(new Rod);
    v[3]->draw(0);
    int j, flag=0;
    for (j=5;j<=9;j++){
    if (space[j]==0)break;
    if (j==9&&space[j]==1)flag=1;
    }
    if(flag==1){
        for (j=4;j>=0;j--){
            if (space[j]==0)break;
        }
    }
    v.push_back(new Car());
    v[4]->draw(j);   //remember to free the memory!!!

    glutSwapBuffers();
    glFlush();
    timer++; //std::cout << timer << std::endl;
}

int main (int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Interstellar Car Park");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 0);
    glutMainLoop();
}
