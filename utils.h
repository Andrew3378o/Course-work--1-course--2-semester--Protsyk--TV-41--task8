#ifndef UTILS_H
#define UTILS_H

#include <unordered_map>
#include <vector>
#include "cell.h"

using namespace std;
long long count( unordered_map<Cell *, vector<vector<int>>> &horizontal, unordered_map<Cell *, vector<vector<int>>> &vertical);
bool have_common(const vector<int> &big, const vector<int> &small);
void filter_vectors(vector<vector<int>> &v1, vector<vector<int>> &v2);
Cell *find_horizontal(Cell *cells[], int i, int j);
Cell *find_vertical(Cell *cells[], int i, int j);
bool check_horizontal(Cell *cells[], int i, int j);
bool check_vertical(Cell *cells[], int i, int j);
vector<pair<int, int>> generate_horizontal_group(Cell *cells[], int rows, int cols);

#endif