#ifndef LOCATION_H
#define LOCAITON_H

class Location {
    public: 
        int row, column;
        double maxValue;

        Location() : row(0), column(0), maxValue(0) {}
};

#endif