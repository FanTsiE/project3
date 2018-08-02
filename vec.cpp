#include "vec.h"
#include <cmath>

Vec::Vec(float _x, float _y) {
    x = _x; y = _y;
}
float Vec::getX() {return x;}
float Vec::getY() {return y;}

Vec Vec::operator+ (Vec v) {
    return Vec(x + v.getX(), y + v.getY());
}
Vec Vec::operator- (Vec v) {
    return Vec(x - v.getX(), y - v.getY());
}
Vec Vec::operator* (float k) {
    return Vec(k * x, k * y);
}
Vec Vec::operator* (Vec v) {
    return Vec(x * v.getX(), y * v.getY());
}
Vec Vec::operator<< (float t) {
    return Vec(cosf(t)*x-sinf(t)*y,sinf(t)*x+cosf(t)*y);
}
Vec Vec::operator>> (float t) {
    return Vec(cosf(-t)*x-sinf(-t)*y,sinf(-t)*x+cosf(-t)*y);
}
