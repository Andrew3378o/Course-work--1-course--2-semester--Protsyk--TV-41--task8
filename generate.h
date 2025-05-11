#ifndef GENERATE_H
#define GENERATE_H

#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include "cell.h"
using namespace std;

void generate(vector<int> &current, int start, int cells_left, int sum_left, vector<vector<int>> &result);
unordered_map<cell *, vector<vector<int>>> generate_horizontal(cell *cells[], int rows, int cols);
unordered_map<cell *, vector<vector<int>>> generate_vertical(cell *cells[], int rows, int cols);
map<pair<int, int>, set<int>> generate_guesses(cell *cells[], int rows, int cols);

#endif