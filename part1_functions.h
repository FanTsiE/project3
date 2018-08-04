//
// Created by 16072 on 2018/8/2.
//


#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>

using namespace std;

#ifndef PROJECT_PART1_FUNCTIONS_H
#define PROJECT_PART1_FUNCTIONS_H

#endif //PROJECT_PART1_FUNCTIONS_H



struct Parking_lot{
    int floor;
    int type;       //1 for van, 2 for car, 3 for motorbike, 4 for bicycle
    int state;      //1 for available, 0 for occupied
    int arrival[3];
    int leave;
    int price;
};

struct car{
    int typec;
    int arrival[3];
    int floor;
    int leave;
    int price;
};

void initailizeP(vector<Parking_lot> *pl);

void addcar(vector<Parking_lot> *pl,int t[],int count);

void settime(int time[]);

int fee(int flag,int d);

int searchfloor(vector<Parking_lot> *pl,int flag,car *tmp,int d, int count);

void aticket(car tmp);

void checkcars(vector<Parking_lot> *pl, int count);

void dticket(vector<Parking_lot>::iterator iter);

void addday(int arrival[3], int night);