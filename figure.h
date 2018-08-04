#ifndef P3_FIGURE_H
#define P3_FIGURE_H

#include <cmath>
#include "vec.h"

class Figure {
protected:
    Vec anchor;
public:
    Figure() : anchor(0, 0) {}
    Vec getAnchor() {return anchor;}
    void setAnchor(Vec a) {anchor = a;}
    virtual void draw() = 0;
    virtual void move(Vec dir) = 0;
    virtual void rotate(float angle) = 0;
    virtual void zoom(float k) = 0;
    ~Figure() = default;             //revised by CLion
};

class ColoredFig : public Figure {
protected:
    float r, g, b;
public:
    ColoredFig(float r_ = 0, float g_ = 0, float b_ = 0) {r = r_; g = g_; b = b_;};
    void randomColor();
};

class Quadrilateral : public ColoredFig {
protected:
    Vec p1, p2, p3, p4;
public:
    Quadrilateral(Vec anchor_ = {0,0}, Vec p1_ = {0,0}, Vec p2_ = {0,0}, Vec p3_ = {0,0}, Vec p4_ = {0,0},
            float r_ = 0, float g_ = 0, float b_ = 0) : //anchor(anchor_.getX(),anchor_.getY()),
                    p1(p1_.getX(),p1_.getY()), p2(p2_.getX(),p2_.getY()), p3(p3_.getX(),p3_.getY()), p4(p4_.getX(),p4_.getY()) {
        r = r_; g = g_; b = b_; setAnchor(anchor_);
    };
    void draw();
    void move(Vec dir);
    void rotate(float angle);
    void zoom(float k);
    //~Quadrilateral() = default;
};

class Circle : public ColoredFig {
protected:
    Vec center;
    float radius;
public:
    Circle (Vec anchor_ = {0,0}, Vec center_ = {0,0}, float radius_ = 0, float r_ = 0, float g_ = 0, float b_ = 0) :
            center(center_.getX(),center_.getY()) {
        radius = radius_; r = r_; g = g_; b = b_; setAnchor(anchor_);
    }
    void draw();
    void move(Vec dir);
    void rotate(float angle);
    void zoom(float k);
};

class Semicircle : public ColoredFig {
protected:
    Vec center, p1;
    float radius;
public:
    Semicircle (Vec anchor_ = {0,0}, Vec center_ = {0,0}, Vec p1_ = {0,0}, float r_ = 0, float g_ = 0, float b_ = 0) :
            center(center_.getX(),center_.getY()), p1(p1_.getX(),p1_.getY()) {
        Vec tmp = p1 - center;
        r = r_; g = g_; b = b_; radius = sqrtf(powf(tmp.getX(),2.0)+powf(tmp.getY(),2.0)); setAnchor(anchor_);
    }
    void draw();
    void move(Vec dir);
    void rotate(float angle);
    void zoom(float k);
};
#endif //P3_FIGURE_H
