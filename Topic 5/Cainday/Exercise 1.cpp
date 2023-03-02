/*
    (Monte Carlo Simulation)
    A square is divided into four smaller regions as shown
    below in (a). If you throw a dart into the square 1 million
    times, what is the probability for a dart to fall into an 
    odd-numbered region? Write a program to simulate the process
    and display the result.

    (Hint: Place the center of the square in the center of a 
    coordinate system, as shown in (b). Randomly generate a 
    point in the square and count the number of times for a
    point to fall into an odd-numbered region.)

    
    x >= -50     x <= 50
    x < 0        x > 0
    ------------|-------------
    |           | \          |
    |           |   \    2   | 
    |           |     \      |  y <= 50
    |           |   3   \    |  y > 0
    |           |         \  |
    |     1     |-------------
    |           |            |
    |           |            |  y < 0
    |           |      4     |  y >= -50
    |           |            |
    |           |            |
    |-----------|-------------

*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));

    int r1 = 0,
        r2 = 0,
        r3 = 0,
        r4 = 0;

    const int   area = 100;
    const float side = area / 2;
    int length = 1000000;

    for (int i = 0; i < length; i++) {
        // generate random coords inside the square
        float x, y;
        x = (rand() % area) - side;
        y = (rand() % area) - side;

        // if point is inside the square
        if (
            x >= -side && x <= side &&
            y >= -side && y <= side   
        ) {
            // region 1
            if (x <= 0) {
                cout << "r1: (" << x << ", " << y << ")";
                r1++;
            }

            // region 4 
            else if (x >= 0 && y <= 0) {
                cout << "r4: (" << x << ", " << y << ")";
                r4++;
            }

            // region 3 & 2
            else if (x >= 0 && y >= 0) {
                float slope = x * (-side / side) + side;

                if (y <= slope) {
                    cout << "r3: (" << x << ", " << y << ")";
                    r3++;
                }
                else {
                    cout << "r2: (" << x << ", " << y << ")";
                    r2++;
                }
            }
        }
        else {
            cout << "point is out of bounds";
        }
        cout << endl;
    }

    cout << "region 1: " << r1 << endl
         << "region 2: " << r2 << endl
         << "region 3: " << r3 << endl
         << "region 4: " << r4 << endl;

    return 0;
}