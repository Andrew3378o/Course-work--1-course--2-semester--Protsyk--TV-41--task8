/* ----------------------------------------------------------------<Header>-
 Name: task8.cpp
 Title: Kakuro solver

 Group: TV-41
 Student: Protsyk A.V.

 Written: 2025-04-25
 Revised: 2025-05-16

 Description: Write an algorithm for solving the problem and implement it 
 as a program in ANSI C++. In each white cell, write the numbers from 1 to 9.
 The sum of the numbers in the horizontal block of white cells is indicated
 to the left of this block of white cells, and the sum of the numbers in 
 the vertical block of white cells is indicated above this block. 
 In each block, you cannot use the same number more than once.
 ------------------------------------------------------------------</Header>-*/
#include <iostream>
#include <string>
#include "cell.h"
#include "print.h"
#include "generate.h"
#include "utils.h"
#include "solve.h"
using namespace std;

int main(){

    print_title("Hello and welcome to my Kakuro solver programm!", SIZE);
    print_title("Type \"next\" to look at the next puzzle and its solution.", SIZE);
    print_title("Type \"exit\" to exit the programm.", SIZE);
    cout << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
 
    string exit = "exit", next = "next", user_input;
    get_input(next, exit, user_input);
    
    int rows1 = 10, cols1 = 10;
    Cell *cells1[] = {
        new Cell[cols1]{0, {0, 23}, {0, 28}, {0, 22}, {0, 5}, {0, 28}, {0, 28}, 0, {0, 10}, {0, 26}},
        new Cell[cols1]{{39, 0}, 1, 1, 1, 1, 1, 1, {3, 0}, 1, 1},
        new Cell[cols1]{{23, 0}, 1, 1, 1, 1, 1, 1, {9, 22}, 1, 1},
        new Cell[cols1]{{24, 0}, 1, 1, 1, {29, 21}, 1, 1, 1, 1, 1},
        new Cell[cols1]{{17, 0}, 1, 1, {23, 17}, 1, 1, 1, 1, 1, 1},
        new Cell[cols1]{0, {0, 10}, {4, 22}, 1, 1, {17, 28}, 1, 1, {0, 23}, {0, 13}},
        new Cell[cols1]{{39, 0}, 1, 1, 1, 1, 1, 1, {13, 22}, 1, 1},
        new Cell[cols1]{{26, 0}, 1, 1, 1, 1, 1, {23, 5}, 1, 1, 1},
        new Cell[cols1]{{11, 0}, 1, 1, {27, 0}, 1, 1, 1, 1, 1, 1},
        new Cell[cols1]{{3, 0}, 1, 1, {23, 0}, 1, 1, 1, 1, 1, 1}
    };

    solve(cells1, rows1, cols1);
    print(cells1, rows1, cols1);
    
    get_input(next, exit, user_input);

    int rows2 = 7, cols2 = 7;
    Cell *cells2[] = {
        new Cell[cols2]{0, 0, 0, {0, 7}, {0, 16}, 0, 0},
        new Cell[cols2]{0, 0, {15, 35}, 1, 1, {0, 35}, {0, 4}},
        new Cell[cols2]{0, {26, 16}, 1, 1, 1, 1, 1},
        new Cell[cols2]{{12, 0}, 1, 1, {0, 9}, {7, 19}, 1, 1},
        new Cell[cols2]{{27, 0}, 1, 1, 1, 1, 1, {0, 6}},
        new Cell[cols2]{0, {34, 0}, 1, 1, 1, 1, 1},
        new Cell[cols2]{0, {26, 0}, 1, 1, 1, 1, 1}
    };

    solve(cells2, rows2, cols2);
    print(cells2, rows2, cols2);

    get_input(next, exit, user_input);

    int rows3 = 10, cols3 = 10;
    Cell *cells3[]{
        new Cell[cols3]{0, {0, 17}, {0, 15}, {0, 32}, 0, 0, {0, 16}, {0, 7}, {0, 16}, 0},
        new Cell[cols3]{{21, 0}, 1, 1, 1, 0, {11, 28}, 1, 1, 1, {0, 29} },
        new Cell[cols3]{{11, 0}, 1, 1, 1, {29, 21}, 1, 1, 1, 1, 1},
        new Cell[cols3]{0, {27, 0}, 1, 1, 1, 1, {8, 0}, 1, 1, 1},
        new Cell[cols3]{0, {0, 11}, {21, 34}, 1, 1, 1, {0, 21}, {15, 17}, 1, 1},
        new Cell[cols3]{{45, 0}, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        new Cell[cols3]{{8, 0}, 1, 1, {0, 10}, {13, 0}, 1, 1, 1, {0, 9}, 0},
        new Cell[cols3]{{20, 0}, 1, 1, 1, {12, 16}, 1, 1, 1, 1, {0, 16}},
        new Cell[cols3]{{29, 0}, 1, 1, 1, 1, 1, {11, 0}, 1, 1, 1},
        new Cell[cols3]{0, {12,0}, 1, 1, 1, 0, {22, 0}, 1, 1, 1}
    };

    solve(cells3, rows3, cols3);
    print(cells3, rows3, cols3);

    for (int i = 0; i < rows1; i++){
        delete[] cells1[i];
    }

    for (int i = 0; i < rows2; i++){
        delete[] cells2[i];
    }

    for (int i = 0; i < rows3; i++){
        delete[] cells3[i];
    }

    cout << endl;
    print_title((string)"Thank you for using my programm <3", SIZE);
    cout << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;

    return 0;
}