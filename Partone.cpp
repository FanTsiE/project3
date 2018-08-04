/* Still unfinished...will be debugged completely if more time is given*/
/*I just put it here in advance*/
/*For the project, SZW's is perfect*/
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <list>
#include <cstring>
#include "Partone.h"
using namespace std;

void ParkInit(vector<parklot> carpark){
    parklot temp;
    carpark.resize(60);
    for (int i=0;i<=4;i++){
        for (int j=0;j<=4*(i+1)-1;j++){
            if ((j+1)%4==1) {
                carpark[4*i+j].type = (char *)"van";
                carpark[4*i+j].occupy=0;
            }
            if ((j+1)%4==2){
                carpark[4*i+j].type=(char *)"car";
                carpark[4*i+j].occupy=0;
            }
            if ((j+1)%4==3){
                carpark[4*i+j].type=(char *)"motorbike";
                carpark[4*i+j].occupy=0;
            }
            if ((j+1)%4==0){
                carpark[4*i+j].type=(char *)"bicycle";
                carpark[4*i+j].occupy=0;
            }
        }
    }
}
double *time(double minute,double hour,double day,double month){
    double *time;
    time=new double[4];
    *(time+0)=minute;
    *(time+1)=hour;
    *(time+2)=day;
    *(time+3)=month;
    minute=minute+5;
    if (minute==60){
        minute=0;
        hour=hour+1;
    }
    if (hour==24){
        hour=0;
        day=day+1;
    }
    if (day==30){
        day=1;
        month=month+1;
    }
    return time;
}
void venter(vector<parklot> carpark,int time){
    long long seed = chrono::high_resolution_clock::now().time_since_epoch().count() ;
    mt19937 rand_generator(seed) ;
    uniform_int_distribution<int> dist(6,666) ;
    vehicle vehicle1;
    int a=dist(rand_generator)%4+1;
    if (a==1){ vehicle1.type=(char*)"van"; }
    if (a==2){ vehicle1.type=(char*)"car"; }
    if (a==3){ vehicle1.type=(char*)"motorbike"; }
    if (a==0){ vehicle1.type=(char*)"bicycle"; }
    cout<<vehicle1.type<<endl;
    vehicle1.arrivetime=time;
   vector<parklot>::iterator it;
    int cnt=0,row=0,pos=0;
   for(it=carpark.begin(); it !=carpark.end(); ++it){
       if (strcmp(it->type,vehicle1.type)){
           it->occupy=1;
           it->arrivetime=vehicle1.arrivetime;
           break;
       }
       cnt++;
       if ((cnt%4)%2==1)row++;
       pos=cnt-4*row;
   }
    FILE *fp=fopen("Arrival ticket.txt","a+");
    fprintf(fp,"Time of arrival:%f\nType of vehicle: %s\nEmpty position: %dF,%d\n",vehicle1.arrivetime,vehicle1.type,row,pos);
    fclose(fp);
}

void vexit(vector<parklot> carpark,int time){
    long long seed = chrono::high_resolution_clock::now().time_since_epoch().count() ;
    mt19937 rand_generator(seed) ;
    uniform_int_distribution<int> dist(6,666) ;
    int floor=dist(rand_generator)%4;
    int pos=dist(rand_generator)%(floor+1);
    if (!carpark.empty()) {
        while (carpark[4 * floor + pos].occupy == 0) {
            floor = dist(rand_generator) % 4;
            pos = dist(rand_generator) % floor;
        }
        carpark[4 * floor + pos].timespent = time - carpark[floor * 4 + pos].arrivetime;
        carpark[floor * 4 + pos].price = carpark[floor * 4 + pos].timespent * 10;
        FILE *fp = fopen("Departure ticket.txt", "a+");
        fprintf(fp, "Time spent: %f\nType of vehicle: %s\nPrice: %f", carpark[floor * 4 + pos].timespent,
                carpark[floor * 4 + pos].type, carpark[floor * 4 + pos].price);
        fclose(fp);
    }
}


int main() {
    vector<parklot> carpark;
    int minute, hour, day, month, time1, time0 = 0;
    cin >> time1;
    ParkInit(carpark);
    while (time0 < time1) {
        venter(carpark, time0);
        vexit(carpark, time0);
        time0 = time0 + 5;
    }
    return 0;
}

