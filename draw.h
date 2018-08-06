#ifndef P3_DRAW_H
#define P3_DRAW_H

#include "figure.h"

// This class is used to plot all the moving objects.

class Draw {
private:
    Group* v[11];
    int empty[11];
public:
    Draw();
    void drawAll();
    ~Draw();
};

#endif //P3_DRAW_H
