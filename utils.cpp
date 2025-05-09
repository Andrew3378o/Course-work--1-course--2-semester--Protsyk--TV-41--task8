#include "utils.h"
#include <set>

long long count(
    unordered_map<cell*, vector<vector<int>>> &horizontal,
    unordered_map<cell*, vector<vector<int>>> &vertical)
{
    long long total = 1;

    for (auto &pair : horizontal)
    {
        if (!pair.second.empty())
            total *= pair.second.size();
    }

    for (auto &pair : vertical)
    {
        if (!pair.second.empty())
            total *= pair.second.size();
    }

    return total;
}


bool have_common(const vector<int> &big, const vector<int> &small)
{
    set<int> big_set(big.begin(), big.end());
    for (int x : small)
    {
        if (big_set.find(x) != big_set.end())
            return true;
    }
    return false;
}

void filter_vectors(vector<vector<int>> &v1, vector<vector<int>> &v2)
{
    vector<vector<int>> filtered1, filtered2;

    for (auto &a : v1)
    {
        for (auto &b : v2)
        {
            if (have_common(a, b) || have_common(b, a))
            {
                filtered1.push_back(a);
                filtered2.push_back(b);
                break;
            }
        }
    }

    v1 = filtered1;
    v2 = filtered2;
}

cell *find_horizontal(cell *cells[], int i, int j)
{
    for (int k = j - 1; k >= 0; k--)
    {
        if (cells[i][k].state == condition)
        {
            return &cells[i][k];
        }
    }
    return nullptr;
}

cell *find_vertical(cell *cells[], int i, int j)
{
    for (int k = i - 1; k >= 0; k--)
    {
        if (cells[k][j].state == condition)
        {
            return &cells[k][j];
        }
    }
    return nullptr;
}
