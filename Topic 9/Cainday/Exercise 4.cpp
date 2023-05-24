/*
    (The Rectangle class)
    Design a class named Rectangle to represent a rectangle.
    The class contains:
        - Two double data fields named width and height that specify the width
        and height of the rectangle.
        - A no-arg constructor that creates a rectangle with width 1 and height 1
        - A constructor that creates a default rectangle 
            with the specified width and height
        - The accessor and mutator functions for all the data fields.
        - A function named getArea() that returns the area of this rectangle
        - A function named getPerimeter() that returns the perimeter.

    Draw the UML diagram for the class. Implement the class. Write a test
    program that creates two Rectangle objects. Assign width 4 and height 40
    to the first object and width 3.5 and height 35.9 to the second.
    Display the properties of both objects and find their areas and perimeters.

    +-----------------------------+
    |          Rectangle          |  
    |-----------------------------|
    |   - width: double           |
    |   - height: double          |
    |-----------------------------| 
    |   + Rectangle()             |
    |   + getArea() : double      |
    |   + getPerimeter() : double |
    |   + getWidth() : double     |
    |   + getHeight() : double    |
    |   + setWidth() : void       |
    |   + setHeight() : void      |
    +-----------------------------+

*/

#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {

    Rectangle r1(4, 40);
    Rectangle r2(3.5, 35.9);

    cout << "r1.width: "     << r1.getWidth()     << endl;
    cout << "r1.height: "    << r1.getHeight()    << endl;
    cout << "r1.area: "      << r1.getArea()      << endl;
    cout << "r1.perimeter: " << r1.getPerimeter() << endl;

    cout << "r2.width: "     << r2.getWidth()     << endl;
    cout << "r2.height: "    << r2.getHeight()    << endl;
    cout << "r2.area: "      << r2.getArea()      << endl;
    cout << "r2.perimeter: " << r2.getPerimeter() << endl;

    return 0;
}
