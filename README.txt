part 2

vec.cpp/.h
figure.cpp/.h
park.cpp/.h
main.cpp/.h
last updated 2018/8/6 9:45 by shenzhuowen

notes:
1. remember to free the memory
2. use polymorphism!!!!
3. in Car class, rotate() - rotate around itself, rotate2() - rotate around a certain point
4. remember to randomly generate the UFOs, rockets, teleporters
5. If you have any problems, please contact me! I'm free on Sunday (except 4:00~5:00 pm) and Monday (after 1:00 pm)
shili

***********README FOR THE PROJECT************

Group member:
Shi Li 517370910032
Yuan Fangqi 517370910206
Tang Yiyang 517370910041
Shen Zhuowen 517370910057

*****part 1*****
1.in part1.h file,we mainly use a vector with the data type of struct (vector<struct>)

[parklot]:
1)type for car (char * type)
2)whether occupied (double occupy)
3)price (double price)
4)ariival (double arrive time)
5)time spent here (double timespent)

[vehicle]
1)type for car (char * type)
2)ariival (double arrive time)

2.in the part one.cpp file, we contain functions below:

1)initialization of parking lot .(void ParkInit)
Input:vector<parklot> carpark
process:matching four types(1,2,3,4) of vehicles with four numbers(van, car, motorbike, bicycle)

2)generate time (double *time)
Input:double minute,double hour,double day,double month
Output:time
Process:generate by 60 minutes per hour, 24hours per day and we assume 30days per month here

3)sign in information and print when the car enters (void venter)
Input:vector<parklot> carpark, int time
Output:ticket including time, type and empty position
**we make our ticket a file called arrival ticket here instead of simply printing out

4)sign in information and print when the car exits (void vexit)
Input:vector<parklot> carpark, int time
Output:ticket including time, type and price
**we make our ticket a file called arrival ticket here instead of simply printing out

3.in part1_functions.cpp file
We initialize the parking and process the information of cars here
Comment:
1.we define the price for van is 60, for car is 30, for motorbike is 10 and for bicycle is 2
2.in the function of searching for available parking space, if all suitable parking spaces are occupied, we'll return 2333



*****part 2*****
1.diagram:
Group<-------Figure-------->Colorfig
Group: [car] [ufo] [rocket][teleporter] [rod]
Colorfig: [Line] [Semicircle] [Circle] [Quadrilateral]
(Here we take the triangle as a special quadrilateral that two corners coincide)
2.detailed attributes and methods are explained below:
(Contained in file figure.h)
Figure:
1)the anchor vector (Vec anchor)
2)function of setting anchor (void setAnchor)
3)function of getting anchor (Vec getAnchor)
4)function of drawing (void draw() )
5)function of moving  (void move(Vec dir))
6)function of rotation (void rotate(float angle))
**we take rad instead of degree here to make it more accurate
7)function of zooming (void zoom(float k))
8)its constructor and destructor

Group:
1)function of drawing (void draw() )
2)function of moving  (void move(Vec dir))
3)function of rotation (void rotate(float angle))//we take rad instead of degree here
4)function of zooming (void zoom(float k))
5)its constructor and destructor

Colorfig:
1)color (float r,g, b)
2)function of setting color (void setcolor)
3)function of generating random color (void randomColor)

3.the initialization of vector calculation is contained in file vec.h

4.in the file figure.cpp, we generate all figures with its features
Such as zooming rocket and rotating ufo

5.in the file park.cpp, we draw the frame of parking lot (including the space spared for waiting cars and the moving rod at entrance)

6.in the main.cpp, we do things below:
1)In the function (void RandomParkingLot)we randomly generate the ufo, rocket ,reserved and empty parking space by matching them with random numbers. (1:UFO, 2:Rocket, 3:Reserved, 4:Empty)
2)we guide the car to move in two paths: path above and below
** our method is to find the closest available parking space from left below to right upper side


