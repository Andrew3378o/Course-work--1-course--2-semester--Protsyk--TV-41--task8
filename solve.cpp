#include "solve.h"
#include "generate.h"
#include "utils.h"

void solve(cell *cells[], int rows, int cols)
{
    map<pair<int, int>, set<int>> g = generate_guesses(cells, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        int target_sum = 0;
        int start_j = -1;
        for (int j = 0; j < cols; j++)
        {
            if (cells[i][j].state == condition && cells[i][j].sum_right > 0) {
                target_sum = cells[i][j].sum_right;
                start_j = j + 1;
                set<int> seen;
                int current_sum = 0;

                for (int k = start_j; k < cols; k++)
                {
                    if (cells[i][k].state != target) break;

                    auto key = make_pair(i, k);
                    bool placed = false;

                    for (int n : g[key])
                    {
                        if (seen.count(n)) continue;
                        if (current_sum + n > target_sum) continue;

                        cells[i][k].number = n;
                        seen.insert(n);
                        current_sum += n;
                        placed = true;
                        break;
                    }

                    if (!placed) {
                        cells[i][k].number = 0;
                    }
                }
            }
        }
    }

    for (int j = 0; j < cols; j++)
    {
        int target_sum = 0;
        int start_i = -1;
        for (int i = 0; i < rows; i++)
        {
            if (cells[i][j].state == condition && cells[i][j].sum_down > 0) {
                target_sum = cells[i][j].sum_down;
                start_i = i + 1;
                set<int> seen;
                int current_sum = 0;

                for (int k = start_i; k < rows; k++)
                {
                    if (cells[k][j].state != target) break;

                    auto key = make_pair(k, j);
                    bool placed = false;

                    for (int n : g[key])
                    {
                        if (seen.count(n)) continue;
                        if (current_sum + n > target_sum) continue;

                        cells[k][j].number = n;
                        seen.insert(n);
                        current_sum += n;
                        placed = true;
                        break;
                    }

                    if (!placed) {
                        cells[k][j].number = 0;
                    }
                }
            }
        }
    }
}
