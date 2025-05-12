#ifndef CELL_H
#define CELL_H
#include "enum.h"

class Cell{
public:
    int sum_right;
    int sum_down;
    int number;
    states state;

    Cell(int r, int d) : sum_right(r), sum_down(d), number(0), state(condition) {}
    Cell(int n = 0) : sum_right(0), sum_down(0), number(0){
        state = (n == 0) ? none : target;
    }

    Cell &operator=(const int n[2]){
        sum_right = n[0];
        sum_down = n[1];
        state = condition;
        return *this;
    }

    Cell &operator=(const int n){
        if (n == 0){
            state = none;
        }
        else{
            state = target;
            number = n;
        }
        return *this;
    }
};

#endif