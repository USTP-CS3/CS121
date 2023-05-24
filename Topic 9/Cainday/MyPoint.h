#ifndef MY_POINT_H
#define MY_POINT_H

#include <math.h>

class MyPoint {
    private:
        float x, y;
    
    public: 
        MyPoint(float x, float y) {
            this->x = x;
            this->y = y;
        }

        float getX() {
            return x;
        }

        float getY() {
            return y;
        }

        float distance(MyPoint p) {
            float d = sqrt(pow(p.getX() - this->x, 2) + pow(p.getY() - this->y, 2));
            return d;
        }
};

#endif