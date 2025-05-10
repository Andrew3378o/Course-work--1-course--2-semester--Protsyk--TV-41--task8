#ifndef SOLVE_H
#define SOLVE_H

#include "cell.h"
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

void solve(cell *cells[], int rows, int cols);
void collect_targets(cell *cells[], int rows, int cols, vector<cell *> &targets);
void get_cell_position(cell *cells[], int rows, int cols, cell *target, int &row, int &col);
bool backtrack(cell *cells[], int rows, int cols, const vector<cell *> &targets, int index, unordered_map<cell *, set<int>> &guesses);

#endif
