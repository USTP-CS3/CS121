#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    private:
        double width, height;

    public:
        Rectangle(double width = 1, double height = 1) {
            this->width = width;
            this->height = height;
        }

        double getArea() {
            return (this->width * this->height);
        }

        double getPerimeter() {
            return 2 * (this->width + this->height);
        }

        void setWidth(double width) {
            this->width = width;
        }

        void setHeight(double height) {
            this->height = height;
        }

        double getWidth() {
            return this->width;
        }

        double getHeight() {
            return this->height;
        }
};

#endif