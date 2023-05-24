#ifndef REGULAR_POLYGON_H
#define REGULAR_POLYGON_H

#include <math.h>
#include <cmath>

class RegularPolygon {
    private:
        int n;       // number of side   
        double side; // length of side
        double x;    // center x coord
        double y;    // center y coord
    public:
        RegularPolygon( 
            int n = 3, 
            double side = 1, 
            double x = 0, double y = 0
        ) {
            this->n = n;
            this->side = side;
            this->x = x;
            this->y = y;
        }

        double getPerimeter() const {
            return (this->n * this->side);
        }

        double getArea() const {
            return (this->n * pow(this->side, 2)) / (4 * tan(M_PI / this->n));
        }

        void setN(const int n) {this->n = n;}
        void setSide(const double side) {this->side = side;}
        void setX(const double x) {this->x = x;}
        void setY(const double y) {this->y = y;}

        int getN() const {return this->n;} 
        double getSide() const {return this->side;}
        double getX() const {return this->x;}
        double getY() const {return this->y;}
};


#endif