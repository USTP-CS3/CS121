/*
    (The Fan class)
    Design a class named Fan to represent fan. The class contains:
    - An int data field named speed that specifies the speed of the fan.
        A fan has three speeds indicated with a value 1, 2, or 3.
    - A bool data field names on that specifies whether the fan is on.
    - A double data field named radius that specifies the radius of the fan.
    - A no-arg constructor that creates a default fan with speed 1, on false,
        and radius 5.
    - The accessor and mutator funcitons for all the data fields.

    Draw the UML diagram for the class. Implement the class. Write a test 
    program that creates two Fan objects. Assign speed 3, radius 10, and turn 
    it on to the first object. Assign speed 2, radius 5, and turn it off to 
    the second object. Invoke their accessor functions to display the fan
    properties.

    +--------------------------+
    |           Fan            |
    |--------------------------+
    |   - speed: int           |
    |   - on: bool             |
    |   - radius: double       |
    |--------------------------|
    |   + Fan()                |
    |   + getSpeed(): int      |
    |   + setSpeed(): void     |
    |   + isOn() : bool        |
    |   + setOn() : void       |
    |   + getRadius() : double |
    |   + setRadius(): void    |
    +--------------------------+

*/

#include <iostream>
#include "Fan.h" 
using namespace std;

int main() {

    Fan f1(3, true, 10);
    Fan f2(2, false, 5);

    cout << "f1.radius: " << f1.getRadius() << endl;
    cout << "f1.speed: " << f1.getSpeed() << endl;
    cout << "f1.on: " << f1.isOn() << endl;

    cout << "f2.radius: " << f2.getRadius() << endl;
    cout << "f2.speed: " << f2.getSpeed() << endl;
    cout << "f2.on: " << f2.isOn() << endl;

    return 0;
}