//
// Created by 16072 on 2018/8/2.
//
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <ctime>
#include "part1_functions.h"

/*Following defines the prices per day*/
#define van_pd 60
#define car_pd 30
#define motorbike_pd 10
#define bicycle_pd 2

using namespace std;


void initailizeP(vector<Parking_lot> *pl){
    int f;
    cout << "Input the ideal total floor number: " << endl;
    cin >> f;
    srand(time(NULL));
    for (int i = 0; i < f; ++i) {
        int n;
        cout << "Input the ideal total parking lot number of floor " << i+1 << endl;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int flag = rand()%4+1;
            Parking_lot tmp;
            tmp.type = flag;
            tmp.floor = i+1;
            tmp.state = 1;
            pl->push_back(Parking_lot(tmp));
        }
    }
    ofstream fd1;
    fd1.open("Arrival.txt",ios::trunc);
    fd1.close();
    ofstream fd2;
    fd2.open("Departure.txt",ios::trunc);
    fd2.close();
}

void addcar(vector<Parking_lot> *pl,int t[],int count){
    srand((unsigned int)time(nullptr));
    int n = rand()%10+1;
    for (int i = 0; i < n; ++i) {
        int flag = rand()%4+1;
        car tmp;
        tmp.typec = flag;
        tmp.arrival[0] = t[0];
        tmp.arrival[1] = t[1];
        tmp.arrival[2] = t[2];
        int d = rand()%4+1; //
        tmp.floor = searchfloor(pl,flag,&tmp,d,count);
        aticket(car(tmp));
    }
}

void settime(int time[]){
    cout << "Input the current date in yyyy/mm/dd: ";
    cin >> time[0];
    cin.ignore(1,'/');
    cin >> time[1];
    cin.ignore(1,'/');
    cin >> time[2];
}

int fee(int flag,int d){
    switch (flag){
        case 1:
            return van_pd*d;
        case 2:
            return car_pd*d;
        case 3:
            return motorbike_pd*d;
        case 4:
            return bicycle_pd*d;
        default:
            break;
    }
    return 0;
}

//if not find a proper parking lot, return 2333
int searchfloor(vector<Parking_lot> *pl,int flag,car *tmp,int d, int count){
    vector<Parking_lot>::iterator iter;
    iter = pl->begin();
    while ((iter->type!=flag) | (iter->state == 0)){
        iter++;
        if(iter == pl->end()){
            return 2333;
        }
    }
    iter->state = 0;
    for (int i = 0; i < 3; ++i) {
        iter->arrival[i] = tmp->arrival[i];
    }
    iter->leave = d + count;
    iter->price = fee(flag,d);
    return iter->floor;
}

void aticket(car tmp){
    ofstream fd;
    fd.open("Arrival.txt",ios::app);
    fd << "Arrival: " << tmp.arrival[0] << "/" << tmp.arrival[1] << "/" << tmp.arrival[2] << endl;
    switch(tmp.typec){
        case 1:
            fd << "Type: van." << endl;
            break;
        case 2:
            fd << "Type: car." << endl;
            break;
        case 3:
            fd << "Type: motorbike" << endl;
            break;
        case 4:
            fd << "Type: bicycle" << endl;
            break;
        default:
            break;
    }
    if(tmp.floor!=2333){
        fd << "Hint: on the floor " << tmp.floor << endl;
    } else {
        fd << "Hint: no proper parking lot. " << endl;
    }
    fd.close();
}

void checkcars(vector<Parking_lot> *pl, int count){
    vector<Parking_lot>::iterator iter;
    for (iter = pl->begin(); iter != pl->end(); ++iter) {
        if(iter->state == 0){
            if(iter->leave == count){
                dticket(iter);
                iter->state = 1;
            }
        }
    }
}

void dticket(vector<Parking_lot>::iterator iter){
    ofstream fd;
    fd.open("Departure.txt",ios::app);
    switch(iter->type){
        case 1:
            fd << "Time spent: " << iter->price/van_pd << endl;
            fd << "Type: van." << endl;
            fd << "Price: " << iter->price << endl;
            break;
        case 2:
            fd << "Time spent: " << iter->price/car_pd << endl;
            fd << "Type: car." << endl;
            fd << "Price: " << iter->price << endl;
            break;
        case 3:
            fd << "Time spent: " << iter->price/motorbike_pd << endl;
            fd << "Type: motorbike" << endl;
            fd << "Price: " << iter->price << endl;
            break;
        case 4:
            fd << "Time spent: " << iter->price/bicycle_pd << endl;
            fd << "Type: bicycle" << endl;
            fd << "Price: " << iter->price << endl;
            break;
        default:
            break;
    }
    fd.close();

}

void addday(int arrival[3], int night){
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if ( (arrival[0]%4==0 && arrival[0] %100) || arrival[0] %400==0 )
        days[1]=29;
    else
        days[1]=28;
    arrival[2] += night ;
    while ( arrival[2] > days[arrival[1]-1] )
    {
        arrival[2] -= days[arrival[1]-1] ;
        arrival[1] += 1 ;
        if ( arrival[1] > 12 )
        {
            arrival[1]=1;
            arrival[0] += 1 ;
            if ( (arrival[0]%4==0 && arrival[0] %100) || arrival[0] %400==0 )
                days[1]=29;
            else
                days[1]=28;
        }
    }
}