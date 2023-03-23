/*
    (Game: Eight Queens)
    The classic Eight Queens puzzle is to place eight queens on a 
    chessboard such that no two can attack each other (i.e., no two
    queens are on the same row, same column, or same diagonal).
    There are many possible solutions. Write a program that 
    displays one such solution.
*/

#include <iostream>
#include <random>
#include <time.h>
using namespace std;

void createBoard(int (&board)[8][8]);
void printBoard(int (&board)[8][8]);

int main() {

    srand(time(0));

    int board[8][8];
    
    createBoard(board);

    for (int r = 0; r < 8; r++) {

        // reset board loop if row is all -1
        int yieldCount = 0;
        for (int i = 0; i < 8; i++) {
            if (board[r][i] == -1) 
                yieldCount++;
            else break;
        }
        if (yieldCount == 8) {
            r = 0;
            createBoard(board);
        }

        // choose random cx without -1
        int cx;
        do {
            cx = rand() % 8;
            // cout << cx << endl;
        } while (board[r][cx] == -1);


        // put the queen on cx
        board[r][cx] = 1;        
        

        // put -1 under cx
        for (int i = r+1; i < 8; i++) {
            board[i][cx] = -1;
        }

        // put -1 under cx diagnoals
        for (int i = 1; i < 8; i++) {

            // right
            if (r+i < 8 && cx+i < 8) {
                board[r+i][cx+i] = -1;
            }
            // left
            if (r+i < 8 && cx-i >= 0) {
                board[r+i][cx-i] = -1;
            }
        }  
    }


    printBoard(board);

    return 0;
}

void createBoard(int (&board)[8][8]) {
    for (auto &r : board) {
        for (auto &c : r) {
            c = 0;
        }
    }
}

void printBoard(int (&board)[8][8]) {
    /*
        output formatting
         0 -> ''
         1 -> 1
        -1 -> 0
    */

    cout << "---------------------------------\n";
    for (auto &row : board) {
        cout << "| ";
        for (auto &c : row) {
            if (c == -1)
                cout << 0 << " | ";
            else if (c == 0) 
                cout << "  | ";
            else 
                cout << c << " | ";
        }
        cout << "\n---------------------------------\n";
    }    
}