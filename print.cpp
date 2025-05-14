#include "print.h"
#include <iostream>
#include <iomanip>
using namespace std;

/* ---------------------------------------------------------------------[<]-
 Function: print_row
 Synopsis: Prints a single row of the entire grid of cells.
 ---------------------------------------------------------------------[>]-*/
void print_row(Cell cells[], int cols){
    cout << "+";
    for (int j = 0; j < cols; j++){
        cout << "-----+";
    }
    cout << endl;

    cout << "|";
    for (int i = 0; i < cols; i++){
        if (cells[i].state == NONE){
            cout << "     |";
        }
        else if (cells[i].state == TARGET){
            cout << "  " << cells[i].number << "  |";
        }
        else{
            if (cells[i].sum_right > 0){
                cout << " " << setw(2) << cells[i].sum_right << "> |"; 
            }
            else{
                cout << "     |";
            }
        }
    }
    cout << endl;

    cout << "|";
    for (int i = 0; i < cols; i++){
        if (cells[i].state == NONE || cells[i].state == TARGET){
            cout << "     |";
        }
        else{
            if (cells[i].sum_down != 0){
                cout << " " << setw(2) << cells[i].sum_down << "v |";
            }
            else{
                cout << "     |";
            }
        }
    }
    cout << endl;
}

/* ---------------------------------------------------------------------[<]-
 Function: print
 Synopsis: Prints an entire grid of cells.
 ---------------------------------------------------------------------[>]-*/
void print(Cell *cells[], int rows, int cols){
    for (int i = 0; i < rows; i++){
        print_row(cells[i], cols);
    }
    cout << "+";
    for (int j = 0; j < cols; j++){
        cout << "-----+";
    }
    cout << endl;
}
