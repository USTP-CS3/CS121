/*
    (Financial tsunami)
    Banks lend money to each other. In tough economic times, if a bank goes bankrupt, it may
    not be able to pay bck the lend. A bank's total asset is its curent balance plus its lends
    to other banks.

    Limit = 201;

           0       1       2       3       4
    b0 |  25   | 100.5 |       |       | 320.5 |   = 446
    b1 |       |  125  |  40   |   85  |       |   = 250
    b2 |  125  |       |  175  |   75  |       |   = 375
    b3 |  125  |       |       |   75  |       |   = 200  < unsafe
    b4 |       |       |  125  |       |  181  |   = 306  


    // b3 unsafe affects its link

           0       1       2       3       4
    b0 |  25   | 100.5 |       |       | 320.5 |   = 446
    b1 |       |  125  |  40   |   -   |       |   = 165  < unsafe
    b2 |  125  |       |  175  |   -   |       |   = 300
    b3 |  125  |       |       |   75  |       |   = 200  < unsafe
    b4 |       |       |  125  |       |  181  |   = 306  


    // b1 unsafe affects its link

           0       1       2       3       4
    b0 |  25   |   -   |       |       | 320.5 |   = 345.5
    b1 |       |  125  |  40   |   -   |       |   = 165  < unsafe
    b2 |  125  |       |  175  |   -   |       |   = 300
    b3 |  125  |       |       |   75  |       |   = 200  < unsafe
    b4 |       |       |  125  |       |  181  |   = 306  


    // since no new unsafe, therefore
    // bank 3 and 1 are unsafe
*/
#include <iostream>
#include <iomanip>
using namespace std;

const short MAX = 5;

int main() {

    short num;
    float limit = 201;
    bool  unsafe[MAX] = {};
    float banks[MAX][MAX] = {};

    /*
    float banks[MAX][MAX] = {
        {25,   100.5,  0,     0,   320.5},
        {0,    125,    40,    85,  0    },
        {125,  0,      175,   75,  0    },
        {125,  0,      0,     75,  0    },
        {0,    0,      125,   0,   181  },
    };
    */

    cout << "(Number of banks, Limit): ";
    cin >> num >> limit;

    cout << "(Initial amount, Lended count, | Bank index, Amount, ... |)\n";
    
    for (short i = 0; i < num; i++) {
        
        short lendCount = 0;

        cout << "> ";
        cin >> banks[i][i];
        cin >> lendCount;

        if (lendCount > MAX) {
            cout << "above maximum number of banks limit\n";
            break;
        }

        for (short j = 0; j < lendCount; j++) {
            short idx;
            float amount;
            
            cin >> idx;
            cin >> amount;
            
            banks[i][idx] = amount;
        }
    }

    short recheck = 0;
    do {
        for (short i = 0; i < MAX; i++) {
            float sum = 0;

            cout << "|";
            for (short j = 0; j < MAX; j++) {

                cout << setw(5);

                (!banks[i][j]) 
                    ? cout << '-' 
                    : cout << banks[i][j];
 
                cout << setw(5) << "| ";

                sum += banks[i][j];
            }

            cout << setw(3) << " = " << sum;

            if (sum < limit) {
                cout << "  < unsafe";

                // skip if already recorded
                if (unsafe[i] == 0) {
                    unsafe[i] = 1;
                    recheck += 1;

                    // update affected banks
                    for (short j = 0; j < MAX; j++) {
                        if (i == j) continue;
                        banks[j][i] = 0;
                    }
                }
            }

            cout << endl;
        }
        
        cout << endl;

    } while(recheck-- > 0);

 
    cout << "Unsafe banks: ";
    for (int i = 0; i < MAX; i++) {
        if (unsafe[i] == 1) {
            cout << i << ", ";
        }    
    }
    cout << endl;

    return 0;
}
