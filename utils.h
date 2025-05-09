#ifndef UTILS_H
#define UTILS_H

#include <unordered_map>
#include <vector>
#include "cell.h"

using namespace std;
long long count( unordered_map<cell *, vector<vector<int>>> &horizontal, unordered_map<cell *, vector<vector<int>>> &vertical);
bool have_common(const vector<int> &big, const vector<int> &small);
void filter_vectors(vector<vector<int>> &v1, vector<vector<int>> &v2);
cell *find_horizontal(cell *cells[], int i, int j);
cell *find_vertical(cell *cells[], int i, int j);

#endif