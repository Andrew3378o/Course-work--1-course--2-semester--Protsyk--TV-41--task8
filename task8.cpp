#include <iostream>
#include <iomanip>
using namespace std;

enum states
{
    none,
    target,
    condition
};

class cell
{
public:
    int sum_right;
    int sum_down;
    int number;
    states state;

    cell(int r, int d) : sum_right(r), sum_down(d), number(0), state(condition) {}
    cell(int n = 0) : sum_right(0), sum_down(0), number(0)
    {
        state = (n == 0) ? none : target;
    }

    cell &operator=(const int n[2])
    {
        sum_right = n[0];
        sum_down = n[1];
        return *this;
    }

    cell &operator=(const int n)
    {
        if (n == 0)
        {
            state = none;
        }
        else
        {
            state = target;
        }
        return *this;
    }
};

void print_row(cell cells[], int cols)
{
    cout << "+";
    for (int j = 0; j < cols; j++)
    {
        cout << "-----+";
    }
    cout << endl;

    cout << "|";
    for (int i = 0; i < cols; i++)
    {
        if (cells[i].state == none)
        {
            cout << "     |";
        }
        else if (cells[i].state == target)
        {
            cout << "  0  |";
        }
        else
        {
            if (cells[i].sum_right > 0)
                cout << " " << setw(2) << cells[i].sum_right << "> |";
            else
                cout << "     |";
        }
    }

    cout << endl;
    cout << "|";
    for (int i = 0; i < cols; i++)
    {
        if (cells[i].state == none || cells[i].state == target)
        {
            cout << "     |";
        }
        else
        {
            if (cells[i].sum_down != 0)
            {
                cout << " " << setw(2) << cells[i].sum_down << "v |";
            }
            else
            {
                cout << "     |";
            }
        }
    }
    cout << endl;
}

void print(cell *cells[], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        print_row(cells[i], cols);
    }
    cout << "+";
    for (int j = 0; j < cols; j++)
    {
        cout << "-----+";
    }
    cout << endl;
}

int main()
{
    int rows = 10, cols = 10;
    cell *c[rows] = {
        new cell[cols]{0, {0, 23}, {0, 28}, {0, 22}, {0, 5}, {0, 28}, {0, 28}, 0, {0, 10}, {0, 26}},
        new cell[cols]{{39, 0}, 1, 1, 1, 1, 1, 1, {3, 0}, 1, 1},
        new cell[cols]{{23, 0}, 1, 1, 1, 1, 1, 1, {9, 22}, 1, 1},
        new cell[cols]{{24, 0}, 1, 1, 1, {29, 21}, 1, 1, 1, 1, 1},
        new cell[cols]{{17, 0}, 1, 1, {23, 17}, 1, 1, 1, 1, 1, 1},
        new cell[cols]{0, {0, 10}, {22, 4}, 1, 1, {17, 28}, 1, 1, {0, 23}, {0, 13}},
        new cell[cols]{{39, 0}, 1, 1, 1, 1, 1, 1, {13, 22}, 1, 1},
        new cell[cols]{{26, 0}, 1, 1, 1, 1, 1, {23, 5}, 1, 1, 1},
        new cell[cols]{{11, 0}, 1, 1, {27, 0}, 1, 1, 1, 1, 1, 1},
        new cell[cols]{{3, 0}, 1, 1, {23, 0}, 1, 1, 1, 1, 1, 1}};

        print(c, rows, cols);
    return 0;
}