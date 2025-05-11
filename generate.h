#ifndef GENERATE_H
#define GENERATE_H

#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include "cell.h"
#include "group.h"
using namespace std;

void generate(vector<int> &current, int start, int cells_left, int sum_left, vector<vector<int>> &result);
unordered_map<Cell *, vector<vector<int>>> generate_horizontal(Cell *cells[], int rows, int cols);
unordered_map<Cell *, vector<vector<int>>> generate_vertical(Cell *cells[], int rows, int cols);
map<pair<int, int>, set<int>> generate_guesses(Cell *cells[], int rows, int cols);
Group generate_horizontal_group(Cell *cells[], int cols, int i, int j);
Group generate_vertical_group(Cell *cells[], int rows, int i, int j);
vector<Group> generate_horizontal_groups(Cell *cells[], int rows, int cols);
vector<Group> generate_vertical_groups(Cell *cells[], int rows, int cols);

#endif