#include "utils.h"
#include <set>

long long count(
    unordered_map<cell *, vector<vector<int>>> &horizontal,
    unordered_map<cell *, vector<vector<int>>> &vertical)
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

bool check_horizontal(cell *cells[], int i, int j)
{
    cell *clue = find_horizontal(cells, i, j);
    int sum_required = clue->sum_right;
    set<int> seen;
    int sum_current = 0;

    for (int col = j - 1; col > 0; --col)
    {
        if (cells[i][col].state != target)
            break;

        int num = cells[i][col].number;
        if (num != 0)
        {
            if (seen.count(num))
                return false;

            seen.insert(num);
            sum_current += num;
        }
    }

    int total_cells = 0;
    for (int col = j - 1; col > 0 && cells[i][col].state == target; --col)
        ++total_cells;

    if ((int)seen.size() == total_cells)
        return sum_current == sum_required;
    else
        return sum_current < sum_required;
}

bool check_vertical(cell *cells[], int i, int j)
{
    cell *clue = find_vertical(cells, i, j);
    int sum_required = clue->sum_down;
    set<int> seen;
    int sum_current = 0;

    for (int row = i - 1; row > 0; --row)
    {
        if (cells[row][j].state != target)
            break;

        int num = cells[row][j].number;
        if (num != 0)
        {
            if (seen.count(num))
                return false;

            seen.insert(num);
            sum_current += num;
        }
    }

    int total_cells = 0;
    for (int row = i - 1; row > 0 && cells[row][j].state == target; --row)
        ++total_cells;

    if ((int)seen.size() == total_cells)
        return sum_current == sum_required;
    else
        return sum_current < sum_required;
}
