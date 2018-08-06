#ifndef DRAFT2_FIGURE_H
#define DRAFT2_FIGURE_H

// The hierarchy diagram is in diagram.jpg.

#include <vector>
#include <cmath>
#include "vec.h"

class Figure {
protected:
    Vec anchor;
public:
    Figure() : anchor(0, 0) {}
    Vec getAnchor() {return anchor;}
    void setAnchor(Vec a) {anchor = a;}
    virtual void draw(int space) = 0;
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
    void setColor(int r_, int g_, int b_) { r = (float)r_/256; g = (float)g_/256; b = (float)b_/256; }
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
    void setPosition(Vec p1_, Vec p2_, Vec p3_, Vec p4_) {
        p1 = p1_; p2 = p2_; p3 = p3_; p4 = p4_;
    }
    void draw(int space);
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
    void setPosition(Vec center_, float radius_) {
        center = center_; radius = radius_;
    }
    void draw(int space);
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
    void setPosition( Vec center_, Vec p1_) {
        center = center_; p1 = p1_;
    }
    void draw(int space);
    void move(Vec dir);
    void rotate(float angle);
    void zoom(float k);
};

class Line : public ColoredFig {
protected:
    Vec p1, p2;
    float width;
public:
    Line (Vec anchor_ = {0,0}, Vec p1_ = {0,0}, Vec p2_ = {0,0}, float width_ = 0, float r_ = 0, float g_ = 0, float b_ = 0) :
            p1(p1_.getX(),p1_.getY()), p2(p2_.getX(),p2_.getY()) {
        r = r_; g = g_; b = b_; width = width_; setAnchor(anchor_);
    }
    void setPosition(Vec p1_, Vec p2_) {
        p1 = p1_; p2 = p2_;
    }
    void setWidth(float width_) { width = width_; }
    void draw(int space);
    void move(Vec dir);
    void rotate(float angle);
    void zoom(float k);
};

class Group : public Figure{
public:
    Group() {};
    virtual void draw(int space) = 0;
    virtual void move(Vec dir) = 0 ;
    virtual void rotate(float angle) = 0;
    virtual void zoom(float k) = 0;
    virtual ~Group() = default;
};

class Teleporter : public Group{
private:
    Quadrilateral telep;
public:
    Teleporter(int space);
    void draw(int space);
    void move(Vec dir) {}
    void rotate(float angle) {}
    void zoom(float k) {}
    ~Teleporter() = default;
};

class Rocket : public Group{
private:
    Quadrilateral head, wing1, wing2, body, eye1, eye2, mouth, tail;
    float height;
public:
    Rocket(int space);
    void draw(int space);
    void move(Vec dir) {}
    void rotate(float angle) {}
    void zoom(float k);
    ~Rocket() = default;
};

class UFO : public Group{
private:
    Semicircle sc;
    Line l1, l2;
    Quadrilateral t1,t2;
public:
    UFO(int space);
    void draw(int space);
    void move(Vec dir) {}
    void rotate(float angle);
    void zoom(float k) {}
    ~UFO() = default;
};

class Rod : public Group{
private:
    Line l;
public:
    Rod();
    void draw(int space);
    void move(Vec dir) {}
    void rotate(float angle);
    void zoom(float k) {}
    ~Rod() = default;
};

class Car : public Group{
private:
    Quadrilateral cap, body;
    Circle wheel1, wheel2;
public:
    Car();
    void draw(int space);
    void move(Vec dir);
    void rotate(float angle);
    void rotate2(float angle, Vec point); //Rotate around a certain point.
    void zoom(float k) {}
    ~Car() = default;
};
#endif //DRAFT2_FIGURE_H
