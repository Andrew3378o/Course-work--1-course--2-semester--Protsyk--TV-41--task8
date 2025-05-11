#include "generate.h"
#include "enum.h"
#include "utils.h"
#include <map>

void generate(vector<int> &current, int start, int cells_left, int sum_left, vector<vector<int>> &result)
{
    if (cells_left == 0)
    {
        if (sum_left == 0)
            result.push_back(current);
        return;
    }

    for (int i = start; i <= 9; i++)
    {
        if (i > sum_left)
            break;

        current.push_back(i);
        generate(current, i + 1, cells_left - 1, sum_left - i, result);
        current.pop_back();
    }
}

unordered_map<cell *, vector<vector<int>>> generate_horizontal(cell *cells[], int rows, int cols)
{
    unordered_map<cell *, vector<vector<int>>> output;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (cells[i][j].state == condition && cells[i][j].sum_right > 0)
            {
                int d = 0;
                int k = j + 1;

                while (k < cols && cells[i][k].state == target)
                {
                    d++;
                    k++;
                }

                if (d > 0)
                {
                    vector<int> current_sum;
                    vector<vector<int>> result;
                    generate(current_sum, 1, d, cells[i][j].sum_right, result);
                    output[&cells[i][j]] = result;
                }
            }
        }
    }

    return output;
}

unordered_map<cell *, vector<vector<int>>> generate_vertical(cell *cells[], int rows, int cols)
{
    unordered_map<cell *, vector<vector<int>>> output;

    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (cells[i][j].state == condition && cells[i][j].sum_down > 0)
            {
                int d = 0;
                int k = i + 1;

                while (k < rows && cells[k][j].state == target)
                {
                    d++;
                    k++;
                }

                if (d > 0)
                {
                    vector<int> current_sum;
                    vector<vector<int>> result;
                    generate(current_sum, 1, d, cells[i][j].sum_down, result);
                    output[&cells[i][j]] = result;
                }
            }
        }
    }

    return output;
}

map<pair<int, int>, set<int>> generate_guesses(cell *cells[], int rows, int cols)
{
    unordered_map<cell *, vector<vector<int>>> horizontal = generate_horizontal(cells, rows, cols);
    unordered_map<cell *, vector<vector<int>>> vertical = generate_vertical(cells, rows, cols);
    map<pair<int, int>, set<int>> guesses;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (cells[i][j].state != target)
                continue;

            cell *hor = find_horizontal(cells, i, j);
            cell *vert = find_vertical(cells, i, j);

            if (!hor || !vert)
                continue;

            if (!horizontal.count(hor) || !vertical.count(vert))
                continue;

            filter_vectors(horizontal[hor], vertical[vert]);

            set<int> possible;

            for (const auto &comb_hor : horizontal[hor])
            {
                for (const auto &comb_vert : vertical[vert])
                {
                    if (have_common(comb_hor, comb_vert))
                    {
                        vector<int> v = (comb_hor.size() < comb_vert.size()) ? comb_hor : comb_vert;
                        possible.insert(v.begin(), v.end());
                    }
                }
            }

            guesses[{i, j}] = possible;
        }
    }

    return guesses;
}

