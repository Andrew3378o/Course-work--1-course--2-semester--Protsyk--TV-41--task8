#include <iostream>
#include "cell.h"
#include "print.h"
#include "generate.h"
#include "utils.h"
using namespace std;

int main()
{
    int rows = 10, cols = 10;
    cell *cells[rows] = {
        new cell[cols]{0, {0, 23}, {0, 28}, {0, 22}, {0, 5}, {0, 28}, {0, 28}, 0, {0, 10}, {0, 26}},
        new cell[cols]{{39, 0}, 1, 1, 1, 1, 1, 1, {3, 0}, 1, 1},
        new cell[cols]{{23, 0}, 1, 1, 1, 1, 1, 1, {9, 22}, 1, 1},
        new cell[cols]{{24, 0}, 1, 1, 1, {29, 21}, 1, 1, 1, 1, 1},
        new cell[cols]{{17, 0}, 1, 1, {23, 17}, 1, 1, 1, 1, 1, 1},
        new cell[cols]{0, {0, 10}, {4, 22}, 1, 1, {17, 28}, 1, 1, {0, 23}, {0, 13}},
        new cell[cols]{{39, 0}, 1, 1, 1, 1, 1, 1, {13, 22}, 1, 1},
        new cell[cols]{{26, 0}, 1, 1, 1, 1, 1, {23, 5}, 1, 1, 1},
        new cell[cols]{{11, 0}, 1, 1, {27, 0}, 1, 1, 1, 1, 1, 1},
        new cell[cols]{{3, 0}, 1, 1, {23, 0}, 1, 1, 1, 1, 1, 1}};

    print(cells, rows, cols);
    unordered_map<cell *, set<int>> guesses;

    generate_guesses(cells, rows, cols, guesses);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (cells[i][j].state == target)
            {
                cout << i << "-" << j << " : { ";
                for (const int num : guesses[&cells[i][j]])
                {
                    cout << num << " ";
                }
                cout << "}" << endl;
            }
        }
    }
    for (int i = 0; i < rows; i++)
        delete[] cells[i];

    return 0;
}