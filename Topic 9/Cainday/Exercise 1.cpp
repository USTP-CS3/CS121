/*

    (The MyPoint class)
    Design a class named MyPoint to represent a point with 
    x and y coordinates. The class contains:

    - Two data fields x and y that represents the coordinates.
    - A no-arg constructor that creates a point (0, 0)
    - A constructor that constructs a point with specified coordinates
    - Two get functions for data fields x and y, repectively.
    - A function named distance that returns the distance from this point
        to another point of the MyPoint type.

    Draw the UML diagram for the class. Implement the class. 
    Write a test program that creates two points (0, 0) and (10, 30.5)
    and displays the distance between them.

    +------------------------+
    |         MyPoint        |        
    |------------------------|
    |   - x: float           |
    |   - y: float           |
    |------------------------|
    |   + MyPoint()          |
    |   + getX() : float     |
    |   + getY() : float     |
    |   + distance() : float |
    +------------------------+
    
*/

#include <iostream>
#include <iostream>
#include "MyPoint.h"
using namespace std;

int main() {

    MyPoint p1(0, 0);
    MyPoint p2(10, 30.5);

    cout << "p1.x: " << p1.getX() << " " << "p1.y: " << p1.getY() << endl;
    cout << "p2.x: " << p2.getX() << " " << "p2.y: " << p2.getY() << endl;
    cout << "distance: " << p1.distance(p2) << endl;
}