#include <GL/freeglut.h>
#include <cmath>
#include "figure.h"
#include "vec.h"

static const int VERTEX = 100;
static const float PI = 3.14159;

void ColoredFig::randomColor() {
    r = (float) rand() / RAND_MAX; g = (float) rand() / RAND_MAX; b = (float) rand() / RAND_MAX;
}

void Quadrilateral::draw() {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(p1.getX(),p1.getY()); glVertex2f(p2.getX(),p2.getY());
    glVertex2f(p3.getX(),p3.getY()); glVertex2f(p4.getX(),p4.getY());
    glEnd();
}

void Quadrilateral::move(Vec dir) {
    p1 = p1 + dir; p2 = p2 + dir; p3 = p3 + dir; p4 = p4 + dir;
}

void Quadrilateral::rotate(float angle) {
    p1 = ((p1 - getAnchor()) << angle) + getAnchor(); p2 = ((p2 - getAnchor()) << angle) + getAnchor();
    p3 = ((p3 - getAnchor()) << angle) + getAnchor(); p4 = ((p4 - getAnchor()) << angle) + getAnchor();
}

void Quadrilateral::zoom(float k) {
    p1 = ((p1 - getAnchor()) * k) + getAnchor(); p2 = ((p2 - getAnchor()) * k) + getAnchor();
    p3 = ((p3 - getAnchor()) * k) + getAnchor(); p4 = ((p4 - getAnchor()) * k) + getAnchor();
}

void Circle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < VERTEX; i++)
        glVertex2f(center.getX() + radius * cosf(2 * PI / VERTEX * i), center.getY() + radius * sinf(2 * PI / VERTEX * i));
    glEnd();
}

void Circle::move(Vec dir) { center = center + dir; }

void Circle::rotate(float angle) { center = ((center - getAnchor()) << angle) + getAnchor();}

void Circle::zoom(float k) { center = ((center - getAnchor()) * k) + getAnchor(); radius *= k; }

void Semicircle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    Vec tmp = p1 - center;
    for (int i = 0; i < VERTEX; i++) {
        Vec rot = tmp << (PI / VERTEX * i);
        glVertex2f(rot.getX(), rot.getY());
    }
    glEnd();
}

void Semicircle::move(Vec dir) { center = center + dir; p1 = p1 + dir; }

void Semicircle::rotate(float angle) {
    center = ((center - getAnchor()) << angle) + getAnchor();
    p1 = ((p1 - getAnchor()) << angle) + getAnchor();
}

void Semicircle::zoom(float k) { center = ((center - getAnchor()) * k) + getAnchor(); radius *= k; }