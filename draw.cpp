#include "draw.h"
#include <iostream>
#include <ctime>

void RandomParkingLot(Group **v,int *space){
    //1:UFO, 2:Rocket, 3:Reserved, 4:Empty
    srand((unsigned int)time(NULL));
    int flag;
    for (int i = 0; i < 10; ++i) {
        flag = rand() % 4 + 1;
        switch(flag){
            case 1: v[i] = new UFO(i); space[i] = 1; break;
            case 2: v[i] = new Rocket(i); space[i] = 1; break;
            case 3: v[i] = new Teleporter(i); space[i] = 1; break;
            case 4: v[i] = nullptr; space[i] = 0; break;
            default: break;
        }
    }
    static int FIND[10] = {5,6,7,8,9,4,3,2,1,0};
    flag = 0;
    for (int i = 0; i < 10; i++)
        if (space[FIND[i]] == 0) {
            v[FIND[i]]= new Car();
            space[FIND[i]] = 1;
            flag = 1;
            break;
        }
    if (flag == 0) {
        int tmp = rand() % 10;
        delete v[tmp];
        v[tmp] = new Car;
    }
    v[10] = new Rod;   // to make sure there is at least one rod;
    space[10] = 1;
}

Draw::Draw() {
    for (int i = 0; i <= 10; i++)
        empty[i] = 0;
    RandomParkingLot(v,empty);
}

void Draw::drawAll() {
    for (int i = 0; i <= 10; ++i) {
        if (empty[i] != 0)
            v[i]->draw(i);
    }
}

Draw::~Draw() {
    for (int i = 0; i <= 10; i++) {
        delete(v[i]);
    }
}