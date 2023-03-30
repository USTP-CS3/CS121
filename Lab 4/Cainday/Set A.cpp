/*
    Design a flowchart and write a program that prompts the user to enter the coordinates of the 
    four vertices and displays the area of the four triangles in increasing order. 

    Here is a sample run:

    Enter x1, y1, x2, y2, x3, y3, x4, y4: (-2.5, 2), (4, 4), (3, -2), (-2, -3.5)

    The areas are 1.390 1.517 8.082 8.333

    Note: this program will not work if the points are not sorted adjacently
    - use Topic 7 Exercise 5 for a more improved solution
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {

    // get adjacent vertices
    const short n = 4;
    double v[n][2];
    double outerSegments[n];
    double innerSegments[n];

    cout << fixed << setprecision(5);
    cout << "Enter x1, y1, x2, y2, x3, y3, x4, y4: ";
    for (short i = 0; i < n; i++) {
        cin >> v[i][0];
        cin >> v[i][1];
    }   
    
    // get the line 1 slope v[0] -> v[2]
    const double m1 = (v[2][1] - v[0][1]) / (v[2][0] - v[0][0]);

    // get the line 1 intercept
    const double b1 = v[0][1] - (m1 * v[0][0]);

    // get the line 2 slope v[3] -> v[1]
    const double m2 = (v[1][1] - v[3][1]) / (v[1][0] - v[3][0]);

    // get the line 2 intercept
    const double b2 = v[1][1] - (m2 * v[1][0]);

    // get the x point of intersection
    const double xm = (b2 - b1) / (m1 - m2);

    // get the y point of intersection
    const double ym = (m1 * xm) + b1;    
    
    cout << "m and b: " << "(" << m1 << ", " << b1 << ")\n";
    cout << "Slope: " << "(" << m1 << ", " << m2 << ")\n";
    cout << "Intersection: (" << xm << ", " << ym << ")\n";

    // get outer and inner segments
    for (short i = 0, j = 1; i < n; i++, j++) {
        if (j == n) j = 0;

        double x1, y1, x2, y2;
        
        x1 = v[i][0];
        y1 = v[i][1];
        x2 = v[j][0];
        y2 = v[j][1];

        outerSegments[i] = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        x1 = v[i][0];
        y1 = v[i][1];
        x2 = xm;
        y2 = ym;

        innerSegments[i] = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));;
    }

    // get triangle area
    double total = 0;
    for (short i = 0, j = 1; i < n; i++, j++) {
        if (j == n) j = 0;
        const double a = outerSegments[i];
        const double b = innerSegments[i];
        const double c = innerSegments[j];
        const double s = (a + b + c) / 2;
        const double area = sqrt(s * (s - a) * (s - b) * (s - c));
        total += area;

        cout << "a:" << a << " b:" << b << " c:" << s << " s:" << s << endl;
        cout << "Triangle " << i << " area is: " << area << endl;
    }
    cout << "Total area is: " << total << endl;

    return 0;
}