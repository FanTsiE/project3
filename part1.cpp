#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include "part1_functions.h"



using namespace std;



/*In my programme, I think that "more than one floor,
 * each one being of different size" means in different floors
 * the number of the four kinds of the parking area is different.*/

int main() {
    vector<Parking_lot> pl;
    int cdate[3];
    initailizeP(&pl);
    settime(cdate);
    int n;
    int t= 1;
    cout << "How many days do you want to run your parking lot? " << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        addcar(&pl,cdate,i);
        checkcars(&pl,i);
        addday(cdate,t);
    }
    return 0;
}