#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "cell.h"
#include "group.h"
using namespace std;

bool have_common(const vector<int> &big, const vector<int> &small);
void filter_vectors(vector<vector<int>> &v1, vector<vector<int>> &v2);
Cell* find_horizontal(Cell **cells, int i, int j);
Cell* find_vertical(Cell **cells, int i, int j);
bool check_horizontal(Cell **cells, int i, int j);
bool check_vertical(Cell **cells, int i, int j);
Group& find_group(vector<Group> &groups, pair<int, int> p);

#endif