#include "solve.h"
#include "generate.h"
#include "utils.h"

void solve(cell *cells[], int rows, int cols)
{
    unordered_map<cell *, set<int>> guesses = generate_guesses(cells, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cell &c = cells[i][j];

            if (c.state != target)
                continue;

            vector<int> nums(guesses[&c].begin(), guesses[&c].end());

            for (const int n : nums)
            {
                c.number = n;

                if (check_horizontal(cells, i, j) && check_vertical(cells, i, j))
                {
                    break;
                }

                c.number = 0;
            }
        }
    }
}
