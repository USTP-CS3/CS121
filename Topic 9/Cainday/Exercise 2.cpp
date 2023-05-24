/*
    (Stopwatch)
    Design a class named StopWatch. The class contains:

    - Private data fields startTime and endTime with get functions
    - A no-arg constructor that initializes startTime with the current time.
    - A function named start() that resets the startTime to current time.
    - A function named stop() that sets the endTime to current time.
    - A function named getElapsedTime() that returns the elapsed time for 
        the stop watch in milliseconds.

    Draw the UML diagram for the class. Implement the class. Write a test 
    program that measures the execution time of sorting 100000 numbers using 
    selection sort.

    +------------------------------+
    |           StopWatch          |
    |------------------------------|
    |   - startTime: time_t        |
    |   - endTime: time_t          |
    |------------------------------|
    |   + StopWatch()              |
    |   + start(): void            |
    |   + stop(): void             |
    |   + getElapsedTime(): float  |
    +------------------------------|
*/

#include <iostream>
#include "StopWatch.h"
using namespace std;

int main() {

    StopWatch s = StopWatch();
    s.start();

    for (int i = 0; i < 99999; i++) {
        cout << "nub";
    }

    s.stop();

    cout << "elapsed: " << s.getElapsedTime() << " ms" << endl;

    return 0;
}