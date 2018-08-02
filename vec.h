#ifndef P3_VEC_H
#define P3_VEC_H

class Vec {
private:
    float x,y;
public:
    Vec(float _x, float _y);
    float getX();
    float getY();

    Vec operator+ (Vec v);
    Vec operator- (Vec v);
    Vec operator* (float k);
    Vec operator* (Vec v);
    Vec operator<< (float t);
    Vec operator>> (float t);
};

#endif //P3_VEC_H
