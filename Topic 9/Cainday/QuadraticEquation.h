#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUAITON_H

#include <math.h>

class QuadraticEquation {
    private:
        float a, b, c;
    
    public:
        QuadraticEquation(float a, float b, float c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        float getDiscriminant() {
            return (pow(this->b, 2) - (4 * this->a * this->c));
        }

        float getRoot1() {
            return (-this->b + sqrt(pow(this->b, 2) - (4 * this->a * this->c))) / (2 * this->a);
        }

        float getRoot2() {
            return (-this->b - sqrt(pow(b, 2) - (4 * this->a * this-> c))) / (2 * this->a);
        }

        float getA() {
            return this->a;
        }

        float getB() {
            return this->b;
        }

        float getC() {
            return this->c;
        }         
};

#endif