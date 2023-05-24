/*
    (Geometry: n-sided regular polygon)
    An n-sided regular polygon has n sides of the same length, and all its angles 
    have the same degree (i.e the polygon is both equilateral and equiangular). 
    Design a class named RegularPolygon that contains the following:

    A private int data field named n that defines the number of sides in the polyon.
    A private double data field named side that stores the length of the side.
    A private double data field named x that defines the x-coordinate of the 
        center of the polygon
    A no-arg constructor that creates a regular polygon with n 3, side 1, x 0,
        and y 0.
    A constructor that creates a regular polygon with the specified number of 
        sides and length of side, and centered at (0, 0)
    A constructor that creates a regular polygon with the specified number of
        sides, length of side, and x- and y-coordinates.
    The constant accessor and mutator functions for all data fields.
    The constant function getPerimeter() that returns the perimeter of the polygon.
    The constant function getArea() that returns the area of the polygon.

    Draw the UML diagram for the class. Implement the class. Write a test program
    that creates three RegularPolygon objects, using the no-arg constructor, 
    using RegularPolygon(6, 4), and using RegularPolygon(10, 4, 5.6, 7.8).
    For each object, display its perimeter and area. 

    +------------------------------------+
    |           RegularPolygon           |                   
    |------------------------------------|
    |   - n: int                         |
    |   - side: double                   |
    |   - x: double                      |
    |   - y: double                      |
    |------------------------------------|
    |   + RegularPolygon(int, double,    |
    |                   double, double)  |
    |   + getPerimeter(): double const   |
    |   + getArea(): double const        |
    |   + getN(): int const              |   
    |   + getSide(): double const        |
    |   + getX(): double const           |
    |   + getY(): double const           |
    |   + setN(const int): void          |
    |   + setSide(const double): void    |
    |   + setX(const double): void       |
    |   + setY(const double): void       |
    +------------------------------------+
*/

#include <iostream>
#include "RegularPolygon.h"
using namespace std;

int main() {

    RegularPolygon p1(6, 4);
    p1.setN(6);
    p1.setSide(4);

    cout << "p1.n: "   << p1.getN()    << endl;
    cout << "p1.side " << p1.getSide() << endl;
    cout << "p1.x "    << p1.getX()    << endl;
    cout << "p1.y "    << p1.getY()    << endl;

    RegularPolygon p2(10, 4, 5.6, 7.8);
    p2.setN(10);
    p2.setSide(4);
    p2.setX(5.6);
    p2.setY(7.8);

    cout << "p2.n: "   << p2.getN()    << endl;
    cout << "p2.side " << p2.getSide() << endl;
    cout << "p2.x "    << p2.getX()    << endl;
    cout << "p2.y "    << p2.getY()    << endl;

    return 0;
}