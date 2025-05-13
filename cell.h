#ifndef CELL_H
#define CELL_H
#include "enum.h"

struct Cell{
    int sum_right;
    int sum_down;
    int number;
    states state;

    Cell(int r, int d) : sum_right(r), sum_down(d), number(0), state(CONDITION) {}
    Cell(int n = 0) : sum_right(0), sum_down(0), number(0){
        state = (n == 0) ? NONE : TARGET;
    }

    Cell &operator=(const int n[2]){
        sum_right = n[0];
        sum_down = n[1];
        state = CONDITION;
        return *this;
    }

    Cell &operator=(const int n){
        if (n == 0){
            state = NONE;
        }
        else{
            state = TARGET;
            number = n;
        }
        return *this;
    }
};

#endif