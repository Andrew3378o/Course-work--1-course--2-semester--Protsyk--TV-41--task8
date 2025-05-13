#include <iostream>
#include "cell.h"
#include "print.h"
#include "generate.h"
#include "utils.h"
#include "solve.h"
using namespace std;

int main(){
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

    cout << "\nTest #1" << endl;
    solve(cells1, rows1, cols1);
    print(cells1, rows1, cols1);
    
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

    cout << "\nTest #2" << endl;
    solve(cells2, rows2, cols2);
    print(cells2, rows2, cols2);

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

    cout << "\nTest #3" << endl;
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

    return 0;
}