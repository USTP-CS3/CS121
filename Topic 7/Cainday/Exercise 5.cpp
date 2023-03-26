/*
    (Area of a polygon)
    Write a program that prompts the user to enter the points of a convex polygon
    and display its area. Assume that the polygon has six end points and the 
    points are entered clockwise.

    In this solution, I made a function that sorts the points clockwise
*/

#include <iostream>
#include <vector>
#include <array>
#include <math.h>
using namespace std;

void printVertices(double (&vertice)[6][2]);
void printVertices(vector<array<double, 2>> (&vertice));
void sortVertices(vector<array<double, 2>> (&vertice), bool reverse = false);
void sortClockwise(double (&vertice)[6][2]);
double getConvexArea(double (&vertice)[6][2]);

int main() {

    // sorted
    // -8.5 10   0 11.4   5.5 7.8   6 -5.5   0 -7   -3.5 -3.5

    // scrambled
    //  5.5 7.8 0 -7 6 -5.5 -8.5 10 -3.5 -3.5 0 11.4

    double vertices[6][2] = {};

    cout << "Enter the coordinates of six points: ";

    for (double (&v)[2] : vertices) {
        cin >> v[0];
        cin >> v[1];
        cout << "(" << v[0] << ", " << v[1] << "), ";
    }
    cout << endl;

    sortClockwise(vertices);

    printVertices(vertices);

    const double area = getConvexArea(vertices);
    
    cout << "The total area is: " << area;
    
    return 0;
}

void printVertices(double (&vertice)[6][2]) {
    for (int i = 0; i < 6; i++) {
        cout << "(" << vertice[i][0] << ", " << vertice[i][1] << "), ";
    }
    cout << endl;
}


void printVertices(vector<array<double, 2>> (&vertice)) {
    for (int i = 0; i < vertice.size(); i++) {
        cout << "(" << vertice[i][0] << ", " << vertice[i][1] << "), ";
    }
    cout << endl;
}


void sortVertices(vector<array<double, 2>> (&vertice), bool reverse) { 
    /* insertion sorts x value of vertex */
   
    for (short i = 0; i < vertice.size(); i++) {
        short m = i;

        for (short j = i; j < vertice.size(); j++) {    
            if (reverse) {
                if (vertice[j][0] > vertice[m][0])  {
                    m = j;
                }
            }
            else if (vertice[j][0] < vertice[m][0])  {
                m = j;
            }
        }

        const double bucket[2] = {
            vertice[i][0], 
            vertice[i][1]
        };
        
        vertice[i][0] = vertice[m][0];  
        vertice[i][1] = vertice[m][1];   
        vertice[m][0] = bucket[0];
        vertice[m][1] = bucket[1];
    } 
}

void sortClockwise(double (&vertice)[6][2]) {
   // get the min and max of y
    double minY = vertice[0][1];
    double maxY = vertice[0][1];

    for (double (&v)[2] : vertice) {
        if (v[1] < minY)
            minY = v[1]; 
        if (v[1] > maxY)
            maxY = v[1];
    }
    
    // get the middle line
    const double mean = (maxY + minY) / 2;

    // extract top and bottom vertice
    vector<array<double, 2>> tVertice;
    vector<array<double, 2>> bVertice;

    for (double (&v)[2] : vertice) {
        if (v[1] > mean) {
            array<double, 2> vx = {v[0], v[1]};        
            tVertice.push_back(vx);
        }
        else {
            array<double, 2> vx = {v[0], v[1]};        
            bVertice.push_back(vx);
        }
    }


    sortVertices(tVertice, false); // ascending
    sortVertices(bVertice, true); // descending

    // transfer t and b results to original
    short i;
    for (i = 0; i < tVertice.size(); i++) {
        vertice[i][0] = tVertice[i][0];
        vertice[i][1] = tVertice[i][1];
    }    

    for (short n = 0; n < bVertice.size(); i++, n++) {
        vertice[i][0] = bVertice[n][0];
        vertice[i][1] = bVertice[n][1];
    }
}


double getDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double getConvexArea(double (&vertice)[6][2]) {
    /* triangulation with heron's formula */
    
    double area = 0;

    for (int i = 1; i+1 < 6; i++) {

        const double a = getDistance(
            vertice[i][0], vertice[i][1], vertice[i+1][0], vertice[i+1][1]);
        
        const double b = getDistance(
            vertice[i][0], vertice[i][1], vertice[0][0], vertice[0][1]);

        const double c = getDistance(
            vertice[i+1][0], vertice[i+1][1], vertice[0][0], vertice[0][1]);
    
        const double s = (a + b + c) / 2;

        area += sqrt(s * (s-a) * (s-b) * (s-c));
    }

    return area;

}