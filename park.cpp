#include <gl/freeglut.h>
#include "figure.h"

void drawPark() {
    glColor3f(0.1,0.1,0.1);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-0.8,-0.7); glVertex2f(-0.8, 0.8);
    glVertex2f(-0.8, 0.8); glVertex2f( 0.8,0.8);
    glVertex2f( 0.8, 0.8); glVertex2f( 0.8,-0.6);
    glVertex2f( 0.8,-0.6); glVertex2f(-0.5,-0.6);
    glVertex2f(-0.5,-0.6); glVertex2f(-0.5,-0.7);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    for (int i = 1; i <= 6; i++) {
        glVertex2f(0.2 * (float)i - 0.7, 0.8); glVertex2f(0.2 * (float)i - 0.7, 0.5);
        glVertex2f(0.2 * (float)i - 0.7,-0.6); glVertex2f(0.2 * (float)i - 0.7,-0.3);
    }
    glEnd();
    glColor3f(0.4,0.4,0.4);
    glBegin(GL_QUADS);
    glVertex2f(-0.5,0.05); glVertex2f(0.5,0.05); glVertex2f(0.5,0.15); glVertex2f(-0.5,0.15);
    glEnd();
}