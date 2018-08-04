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
    p1 = p1 + dir; p2 = p2 + dir; p3 = p3 + dir; p4 = p4 + dir; setAnchor(getAnchor() + dir);
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

void Circle::move(Vec dir) { center = center + dir; setAnchor(getAnchor() + dir); }

void Circle::rotate(float angle) { center = ((center - getAnchor()) << angle) + getAnchor();}

void Circle::zoom(float k) { center = ((center - getAnchor()) * k) + getAnchor(); radius *= k; }

void Semicircle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    Vec tmp = p1 - center;
    for (int i = 0; i < VERTEX; i++) {
        Vec rot = tmp << (PI / VERTEX * i);
        glVertex2f(rot.getX() + center.getX(), rot.getY() + center.getY());
    }
    glEnd();
}

void Semicircle::move(Vec dir) { center = center + dir; p1 = p1 + dir; setAnchor(getAnchor() + dir); }

void Semicircle::rotate(float angle) {
    center = ((center - getAnchor()) << angle) + getAnchor();
    p1 = ((p1 - getAnchor()) << angle) + getAnchor();
}

void Semicircle::zoom(float k) { center = ((center - getAnchor()) * k) + getAnchor(); radius *= k; }

void Line::draw() {
    glColor3f(r, g, b);
    glLineWidth(width);
    glBegin(GL_LINES);
    glVertex2f(p1.getX(),p1.getY());
    glVertex2f(p2.getX(),p2.getY());
    glEnd();
}

void Line::move(Vec dir) {
    p1 = p1 + dir; p2 = p2 + dir; setAnchor(getAnchor() + dir);
}

void Line::rotate(float angle) {
    p1 = ((p1 - getAnchor()) << angle) + getAnchor(); p2 = ((p2 - getAnchor()) << angle) + getAnchor();
}

void Line::zoom(float k) {
    p1 = ((p1 - getAnchor()) * k) + getAnchor(); p2 = ((p2 - getAnchor()) * k) + getAnchor();
}

Teleporter::Teleporter(int space) : telep({0,0},{0,0},{0,0},{0,0},{0,0},0.5,0.5,0.5){
    float w = 0.16, h = 0.26, x , y;
    if (space <= 5) { x = -0.48 + 0.2 * space; y = 0.52; }
    else { x = -0.48 + 0.2 * (space - 5); y = -0.58; }
    telep.setPosition({x,y},{x+w,y},{x+w,y+h},{x,y+h});
    telep.randomColor();
}

void Teleporter::draw() {
    static int flag = 0;
    flag++;
    if (flag >= 20) {
        telep.randomColor();
        flag = 0;
    }
    telep.draw();
}

Rocket::Rocket(int space) {
    float x, y;
    height = 0.28;
    if (space <= 5) { x = -0.4 + 0.2 * space; y = 0.65; }
    else { x = -0.4 + 0.2 * (space - 5); y = -0.45; }
    Vec c = {x,y}; //center, i.e., anchor
    setAnchor(c); head.setAnchor(c); wing1.setAnchor(c); wing2.setAnchor(c); body.setAnchor(c);
    eye1.setAnchor(c); eye2.setAnchor(c); mouth.setAnchor(c); tail.setAnchor(c);
    head.setPosition({x-(float)0.03,y+(float)0.06},{x+(float)0.03,y+(float)0.06},{x,y+(float)0.14},{x-(float)0.03,y+(float)0.06});
    head.setColor(102,179,102);
    wing1.setPosition({x-(float)0.03,y},{x-(float)0.07,y-(float)0.11},{x-(float)0.03,y-(float)0.11},{x-(float)0.03,y});
    wing1.setColor(234,140,22);
    wing2.setPosition({x+(float)0.03,y},{x+(float)0.07,y-(float)0.11},{x+(float)0.03,y-(float)0.11},{x+(float)0.03,y});
    wing2.setColor(234,140,22);
    body.setPosition({x-(float)0.03,y-(float)0.11},{x+(float)0.03,y-(float)0.11},{x+(float)0.03,y+(float)0.06},{x-(float)0.03,y+(float)0.06});
    body.setColor(220,220,20);
    tail.setPosition({x-(float)0.02,y-(float)0.14},{x+(float)0.02,y-(float)0.14},{x+(float)0.01,y-(float)0.11},{x-(float)0.01,y-(float)0.11});
    tail.setColor(10,10,10);
    eye1.setPosition({x-(float)0.02,y+(float)0.02},{x-(float)0.01,y+(float)0.02},{x-(float)0.01,y+(float)0.03},{x-(float)0.02,y+(float)0.03});
    eye1.setColor(228,0,127);
    eye2.setPosition({x+(float)0.02,y+(float)0.02},{x+(float)0.01,y+(float)0.02},{x+(float)0.01,y+(float)0.03},{x+(float)0.02,y+(float)0.03});
    eye2.setColor(228,0,127);
    mouth.setPosition({x-(float)0.01,y-(float)0.02},{x+(float)0.01,y-(float)0.02},{x+(float)0.01,y},{x-(float)0.01,y});
    mouth.setColor(0,161,233);
}

void Rocket::draw() {
    static int flag = 0;
    if (height >= 0.14 && flag == 0)
        zoom(0.99);
    else if (height <= 0.28){
        flag = 1;
        zoom((float)1.0/(float)0.99);
    }
    else
        flag = 0;
    head.draw(); wing1.draw(); wing2.draw(); body.draw();
    eye1.draw(); eye2.draw(); mouth.draw(); tail.draw();
}

void Rocket::zoom(float k) {
    head.zoom(k); wing1.zoom(k); wing2.zoom(k); body.zoom(k);
    eye1.zoom(k); eye2.zoom(k); mouth.zoom(k); tail.zoom(k); height *= k;
}

UFO::UFO(int space) {
    float x, y;
    if (space <= 5) { x = -0.4 + 0.2 * space; y = 0.65; }
    else { x = -0.4 + 0.2 * (space - 5); y = -0.45; }
    Vec c = {x,y}; //center, i.e., anchor
    setAnchor(c); sc.setAnchor(c);; l1.setAnchor(c); l2.setAnchor(c); t1.setAnchor(c); t2.setAnchor(c);
    sc.setPosition({x,y},{x+(float)0.06,y});
    sc.setColor(0,0,255);
    l1.setPosition({x,y+(float)0.03},{x+(float)0.06,y+(float)0.06});
    l1.setColor(255,0,0);
    l2.setPosition({x,y+(float)0.03},{x-(float)0.06,y+(float)0.06});
    l2.setColor(255,0,0);
    t1.setPosition({x-(float)0.06,y-(float)0.02},{x-(float)0.02,y-(float)0.02},{x-(float)0.03,y},{x-(float)0.05,y});
    t1.setColor(255,241,0);
    t2.setPosition({x+(float)0.06,y-(float)0.02},{x+(float)0.02,y-(float)0.02},{x+(float)0.03,y},{x+(float)0.05,y});
    t2.setColor(255,241,0);
}

void UFO::draw() {
    l1.draw(); l2.draw(); sc.draw(); t1.draw(); t2.draw();
    rotate(0.01);
}
void UFO::rotate(float angle) {
    sc.rotate(angle); l1.rotate(angle); l2.rotate(angle); t1.rotate(angle); t2.rotate(angle);
}

Rod::Rod() {
    Vec c = {-0.505,-0.7};
    setAnchor(c); l.setAnchor(c);
    l.setPosition({-0.75,-0.7},c);
    l.setColor(255,0,0);
    l.setWidth(2);
}

void Rod::draw() {
    static int timer = 0;
    l.draw();
    if (timer < 80)
        rotate(-PI / 160.0);
    else if (timer >= 240 && timer <= 320)
        rotate(PI / 162.0);
    timer++;
}

void Rod::rotate(float angle) {
    l.rotate(angle);
}

Car::Car() {
    float x = -0.65, y = -0.85;
    Vec c = {x,y};
    setAnchor(c); cap.setAnchor(c); body.setAnchor(c); wheel1.setAnchor(c); wheel2.setAnchor(c);
    cap.setPosition({x-(float)0.08,y+(float)0.02},{x+(float)0.08,y+(float)0.02},{x+(float)0.04,y+(float)0.08},{x-(float)0.04,y+(float)0.08});
    cap.setColor(127,127,255);
    body.setPosition({x-(float)0.12,y-(float)0.08},{x+(float)0.12,y-(float)0.08},{x+(float)0.12,y+(float)0.02},{x-(float)0.12,y+(float)0.02});
    body.setColor(255,191,127);
    wheel1.setPosition({x-(float)0.08,y-(float)0.08},0.02);
    wheel1.setColor(255,127,127);
    wheel2.setPosition({x+(float)0.08,y-(float)0.08},0.02);
    wheel2.setColor(255,127,127);
    rotate(PI / 2.0);
}

void Car::draw() {
    cap.draw(); body.draw(); wheel1.draw(); wheel2.draw();
}

void Car::move(Vec dir) {
    cap.move(dir); body.move(dir); wheel1.move(dir); wheel2.move(dir); setAnchor(getAnchor() + dir);
}

void Car::rotate(float angle) {
    cap.rotate(angle); body.rotate(angle); wheel1.rotate(angle); wheel2.rotate(angle);
}

void Car::rotate2(float angle, Vec point) {
    Vec tmp = getAnchor();
    setAnchor(point); cap.setAnchor(point); body.setAnchor(point); wheel1.setAnchor(point); wheel2.setAnchor(point);
    rotate(angle);
    setAnchor(tmp); cap.setAnchor(tmp); body.setAnchor(tmp); wheel1.setAnchor(tmp); wheel2.setAnchor(tmp);
}