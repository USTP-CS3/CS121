/*
    (Compute total marks for each student)
    Suppose the marks obtained by all students are stored in a two-dimensional array.
    Each row records a student's marks for five tests. For example, the following
    array stores the test marks for eight students. Write a program that displays
    students and the total marks they obtained in five tests, in decreasing order
    of the total marks;

                 T1   T2   T3   T4   T5
    Student 0    12   14   13   14   15
    Student 1    17   13   14   13   13
    Student 2    13   13   14   13   13
    Student 3    19   13   14   17   13
    Student 4    13   15   14   13   16
    Student 5    13   14   14   16   13
    Student 6    13   17   14   18   13
    Student 7    16   13   15   19   12
*/


#include <iostream>
using namespace std;

int main() {

    const short marks[8][5] = {
        {12, 14, 13, 14, 15},
        {17, 13, 14, 13, 13},
        {13, 13, 14, 13, 13},
        {19, 13, 14, 17, 13},
        {13, 15, 14, 13, 16},
        {13, 14, 14, 16, 13},
        {13, 17, 14, 18, 13},
        {16, 13, 15, 19, 12}
    };

    short descending[8][2];

    // get the total mark for each student
    short count = 0;
    for (const short (&r)[5] : marks) {

        short total = 0;
        for (const short (&c) : r ) 
            total += c;

        descending[count][1] = total;
        descending[count][0] = count++;
    }

    // total mark reverse insertion sort
    for (int i = 0; i < 8; i++) {

        // find the maximum index
        short m = i;
        for (int j = i; j < 8; j++) {
            if (descending[j][1] > descending[m][1]) 
                m = j;
        }

        // swap the values
        short bucket[2] = {
            descending[i][0],
            descending[i][1]
        };

        descending[i][0] = descending[m][0];
        descending[i][1] = descending[m][1];
        descending[m][0] = bucket[0];
        descending[m][1] = bucket[1];

        // print the values on the spot
        cout << "Student " << descending[i][0] << ": " << descending[i][1] << endl;
    }

    return 0;
}


