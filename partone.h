/* Still unfinished...will be debugged completely if more time is given*/
/*I just put it here in advance*/
/*For the project, SZW's is perfect*/
#ifndef PROJECT3_PARTONE_H
#define PROJECT3_PARTONE_H
#include <iostream>
#include <vector>
using namespace std;
typedef struct _parklot{
    char* type;
    double occupy;
    double price;
    double arrivetime;
    double timespent;
}parklot;
typedef struct _vehicle{
    char *type;
    double arrivetime;
}vehicle;
void ParkInit(vector<parklot>carpark);
void venter(vector<parklot> carpark, int time);
void vexit(vector<parklot> carpark, int time);
double *time();
#endif //PROJECT3_PART1_H

