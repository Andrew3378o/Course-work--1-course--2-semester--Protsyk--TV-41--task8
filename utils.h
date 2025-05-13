#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <set>
#include "cell.h"
#include <map>
using namespace std;

set<int> same(vector<int> v1, vector<int> v2);
Cell* find_horizontal(Cell **cells, int i, int j);
Cell* find_vertical(Cell **cells, int i, int j);
void filter_guesses(Cell **cells, int rows, int cols, map<pair<int, int>, set<int>> &guesses);

#endif