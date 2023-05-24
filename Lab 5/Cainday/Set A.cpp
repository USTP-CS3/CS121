/*
  (Algebra: 2 x 2 linear equations) 
  Design a class names LinearEquation for a 2 x 2 system of linear equations:

    ax + by = e   x = ed - bf / ad - bc   
    cx + dy = f   y = af - ec / ad - bc

    The class contains:

    - Private data fields a, b, c, d, e, and f
    - A constructor with the arguments for a, b, c, d, e, and f
    - Six get functions for a, b, c, d, e, and f
    - A function named isSolvable() that returns true if ad - bc is not 0
    - Functions getX() and getY() that return the solutions for the equation.

    Draw the UML diagram for the class and then implement the class.
    Write a test program that prompts the user to enter a, b, c, d, e, and f
    and displays the result.

    If ad - bc is 0, report that "The equation has no solution"


    UML DIAGRAM

    |------------------------------------|
    |     Class Name: Linear Equation    |
    |------------------------------------|
    |                                    |
    | Private:                           |
    |   double a, b, c, d, e, f;         |
    |                                    |
    | Public:                            |
    |   Methods:                         |
    |       bool    isSolvable();        |
    |       double  getX();              |
    |       double  getY();              |
    |                                    |
    |------------------------------------|
*/


#include <iostream> 
using namespace std;

class LinearEquation {

    private:
        double a, b, c, d, e, f;

    public:
        LinearEquation(double a, double b, double c, double d, double e, double f) {
            this->a = a;
            this->b = b;
            this->c = c; 
            this->d = d;
            this->e = e;
            this->f = f;
        }

        bool isSolvable() {
            return (this->a * this->d) - (this->b * this->c);
        }

        double getX() {
            return ((this->e * this->d) - (this->b * this->f)) / ((this->a * this->d) - (this->b * this->c));
        }

        double getY() {
            return ((this->a * this->f) - (this->e * this->c)) / ((this->a * this->d) - (this->b * this->c));
        }
};


int main() {
    double a, b, c, d, e, f;

    cin >> a >> b >> c >> d >> e >> f;

    LinearEquation matrix = LinearEquation(a, b, c, d, e, f);

    cout << "Solvable? ";
    (matrix.isSolvable()) ? cout << "True" : cout << "False";
    cout << endl;

    cout << "Matrix X: " << matrix.getX() << endl;
    cout << "Matrix Y: " << matrix.getY() << endl;

    return 0;
}