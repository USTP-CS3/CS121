/*
    (Bioinformatics: find genes)
    Biologists use a sequene of letters A, C, T, and G to model a genome.
    A gene is a substring of a genome that starts after a triplet ATG and
    ends before a triplet TAG, TAA, or TGA. Furthermore, the length of a 
    gene string is a multiple of 3 and the gene does not contain any of 
    the triplets ATG, TAG, TAA, and TGA. Write a program that prompts the 
    user to enter a genome and siplays all genes in the genome. If no gene
    is found in the input sequene, displays no gene.
*/  

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string genome = "TTATGTTTTAAGGATGGGGCGTTAGTT";
    // string genome = "TGTGTGTATAT";
    // cin >> genome;

    const string start = "ATG";
    const string last[] = {"TAG", "TAA", "TGA"};


    int sTrig = 0;
    int dTrig = 0;
    int eTrig[] = {0,0,0};

    bool none = true;
    string gen = "";


    for (char c : genome) {
        // check if prefix is found
        if (sTrig < 3) {
            if (c != start[sTrig]) sTrig = 0;
            if (c == start[sTrig]) sTrig++;
        }
        else {

            // reset substring if start duplicates
            if (dTrig < 3) {
                if (c != start[dTrig]) dTrig = 0;
                if (c == start[dTrig]) dTrig++;
            }
            else {
                dTrig = 0;
                gen = "";
            }
            
            // check if postfix is found
            if (eTrig[0] == 3 || eTrig[1] == 3 || eTrig[2] == 3
            ) {
                // print the substring
                cout << gen.substr(0, gen.length() - 3) << endl;
                
                // reset attributes
                gen = "";
                none = false;
                sTrig = eTrig[0] = eTrig[1] = eTrig[2] = 0;
            }
            else {
                if (c != last[0][eTrig[0]]) eTrig[0] = 0;
                if (c == last[0][eTrig[0]]) eTrig[0]++;

                if (c != last[1][eTrig[1]]) eTrig[1] = 0;
                if (c == last[1][eTrig[1]]) eTrig[1]++;
            
                if (c != last[2][eTrig[2]]) eTrig[2] = 0;
                if (c == last[2][eTrig[2]]) eTrig[2]++;
            }

            // append character to substring
            gen += c;
        }
    }

    if (none) cout << "no genome was found" << endl;

    return 0;
}