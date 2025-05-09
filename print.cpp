#include "print.h"
#include <iostream>
#include <iomanip>
using namespace std;

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
            cout << "  "<< cells[i].number << "  |";
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

void print(cell *cells[], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        print_row(cells[i], cols);
    }
    cout << "+";
    for (int j = 0; j < cols; j++)
    {
        cout << "-----+";
    }
    cout << endl;
}
