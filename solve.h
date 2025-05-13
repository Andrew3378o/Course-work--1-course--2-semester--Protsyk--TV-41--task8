#ifndef SOLVE_H
#define SOLVE_H

#include "cell.h"
#include <vector>
#include <map>
#include <set>
using namespace std;

bool is_board_valid(Cell **cells, int rows, int cols);
bool is_board_complete(Cell **cells, int rows, int cols);
bool find_empty_cell(Cell **cells, int rows, int cols, int &row, int &col);
int count_filled_cells(Cell **cells, int rows, int cols);
int count_total_cells(Cell **cells, int rows, int cols);
void show_progress(int filled, int total);
void solve(Cell **cells, int rows, int cols);
bool solve_helper(Cell **cells, int rows, int cols, int total_cells, map<pair<int, int>, set<int>> guesses);

#endif