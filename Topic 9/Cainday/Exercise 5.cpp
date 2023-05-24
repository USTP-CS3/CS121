/*
    (Algebra: Quadratic Equations)
    Design a class names QuadraticEquation for a quadratic equation
    ax^2 + bx + x = 0. 

    The class contains:
    - Data fields a, b, and c that represent three coefficients.
    - A constructor with arguments for a, b, c
    - Three get functions for a, b, c
    - A function named getDiscriminant() that returns the discriminant
        which is h^2 - 4ac.
    - The functions named getRoo1() and getRoot2() for returning 
        to roots of the equation:
    
    r1 = (-b + sqrt(b^2 - 4ac)) / (2a)
    r2 = (-b - sqrt(b^2 - 4ac)) / (2a)

    These functions are useful only if the discriminant is nonnegative.
    Let these functions return 0 if the discriminant is negative.

    Draw the UML diagram for the class. Implement the class. Write
    a test program that prompts the user to enter the values for
    a, b, c, and displays the result based on the discriminant. 
    If the discriminant is positive, display the two roots.
    If the discriminant is 0, display one root. Otherwiase, display
    "The equation has no real roots".


    +-------------------------------+
    |       QuadraticEquation       |
    |-------------------------------|
    |   - a: float                  |
    |   - b: float                  |
    |   - c: float                  |
    |-------------------------------|
    |   + QuadraticEquation()       |
    |   + getDiscriminant() : float |
    |   + getRoot1() : float        |
    |   + getRoot2() : float        |
    |   + getA() : float            |
    |   + getB() : float            |
    |   + getC() : float            |
    +-------------------------------+

*/

#include <iostream>
#include "QuadraticEquation.h"

using namespace std;


int main() {

    float a, b, c;
    cout << "Enter a, b, c: " << endl;
    cin >> a >> b >> c;

    QuadraticEquation q(a, b, c);

    cout << q.getA() << " " << q.getB() << " " << q.getC() << endl; 
    cout << "Discriminant: " << q.getDiscriminant() << endl;

    if (q.getDiscriminant() > 0) {
        cout << "root 1: " << q.getRoot1() << endl;
        cout << "root 2: " << q.getRoot2() << endl;
    }
    else if (q.getDiscriminant() == 0) {
        cout << "root 1: " << q.getRoot1() << endl;
    }
    else {
        cout << "The equation has no real roots.";
    }

    return 0;
}