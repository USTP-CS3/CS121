/*
    (Sort two-dimensional array in reverse order)
    Write a function to sort a two-dimensional array in reverse order using the 
    following header:

    void reverseSort(int m[][2], int numberOfRows)

    The function performs a sort primarily on the first element in the rows and then
    secondarily on the second element in the rows if the first elements are equal.
    For example, the array {{9,7},{6,12},{9,10},{6,7},{6,6},{9,6}} will be sorted to
    {{9,10},{9,7},{9,6},{6,12},{6,7},{6,6}}.

    Write a test program that prompts the user to enter 12 points, invokes this 
    function, and displays the sorted points.
*/

#include <iostream>
using namespace std;

void reverseSort(int m[][2], int numberOfRows);

int main() {

    int mat[][2] = {{9,7},{6,12},{9,10},{6,7},{6,6},{9,6}};

    reverseSort(mat, sizeof(mat) / sizeof(mat[0])); 

    for (int (&m)[2] : mat) {
        cout << "{" << m[0] << "," << m[1] << "},";
    }

    cout << endl;

    return 0;
}

void reverseSort(int m[][2], int numberOfRows) {

    // sort x with y values
    for (short i = 0; i < numberOfRows; i++) {
        short max = i;
 
        // find the max x, if its equal compare their y
        for (short j = i; j < numberOfRows; j++) {
            if (m[j][0] > m[max][0] || m[j][0] == m[max][0] && m[j][1] > m[max][1]) 
                max = j;
        }

        // swap with i
        const int bucket[2] = { m[i][0], m[i][1] };

        m[i][0] = m[max][0];
        m[i][1] = m[max][1];
        m[max][0] = bucket[0];
        m[max][1] = bucket[1];
    }
}