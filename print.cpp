#include "print.h"
#include <iostream>
#include <string>
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
            cout << "\033[47m" << "  " << "\033[30m" << cells[i].number << "  " << "\033[0m" << "|";
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
        if (cells[i].state == NONE){
            cout << "     |";
        }
        else if(cells[i].state == TARGET){
            cout << "\033[47m" << "     " << "\033[0m"  << "|";
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

/* ---------------------------------------------------------------------[<]-
 Function: print_title
 Synopsis: Prints user-friendly titles.
 ---------------------------------------------------------------------[>]-*/
void print_title(string title, int cols) {
    int len = title.length();

    if (cols == 0 && cols <= len) {
        for (int i = 0; i < len; ++i){
            cout << (i % 6 == 0 ? '+' : '-');
        }
        cout << endl;
        cout << title << endl;
    } 
    else {
        int d = cols * 6 + 1;

        for (int i = 0; i < d; ++i){
            cout << (i % 6 == 0 ? '+' : '-');
        }
        cout << '\n';

        int space_total = d - 2 - len; 
        int space_left = space_total / 2;
        int space_right = space_total - space_left;

        cout << '|' << string(space_left, ' ') << title << string(space_right, ' ') << '|';

        cout << endl;
    }
}

