#ifndef FAN_H
#define FAN_H

class Fan {
    private:
        int speed;
        bool on;
        double radius;

    public:
        Fan(int speed = 1, bool on = false, double radius = 5) {
            this->speed = speed;
            this->on = on;
            this->radius = radius;
        }

        void setSpeed(int speed) {
            this->speed = speed;
        }
        
        int getSpeed() {
            return this->speed;
        }

        void setOn(bool on) {
            this->on = on;
        }

        bool isOn() {
            return this->on;
        }

        void setRadius(double radius) {
            this->radius = radius;
        }

        double getRadius() {
            return this->radius;
        }
};

#endif