#include "generate.h"
#include "enum.h"
#include "utils.h"
#include <map>

void generate(vector<int> &current, int start, int cells_left, int sum_left, vector<vector<int>> &result) {
    if (cells_left == 0) {
        if (sum_left == 0) {
            result.push_back(current); 
        }
        return;
    }

    for (int i = start; i <= 9; i++) {
        if (i > sum_left) {
            break;
        }

        current.push_back(i);
        generate(current, i + 1, cells_left - 1, sum_left - i, result);
        current.pop_back();
    }
}

unordered_map<Cell*, vector<vector<int>>> generate_horizontal(Cell **cells, int rows, int cols) {
    unordered_map<Cell*, vector<vector<int>>> output;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (cells[i][j].state == CONDITION && cells[i][j].sum_right > 0) {
                int d = 0;
                int k = j + 1;

                while (k < cols && cells[i][k].state == TARGET) {
                    d++;
                    k++;
                }

                if (d > 0) {
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

unordered_map<Cell*, vector<vector<int>>> generate_vertical(Cell **cells, int rows, int cols) {
    unordered_map<Cell *, vector<vector<int>>> output;

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (cells[i][j].state == CONDITION && cells[i][j].sum_down > 0) {
                int d = 0;
                int k = i + 1;

                while (k < rows && cells[k][j].state == TARGET) {
                    d++;
                    k++;
                }

                if (d > 0) {
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

map<pair<int, int>, set<int>> generate_guesses(Cell **cells, int rows, int cols){
    unordered_map<Cell *, vector<vector<int>>> horizontal = generate_horizontal(cells, rows, cols);
    unordered_map<Cell *, vector<vector<int>>> vertical = generate_vertical(cells, rows, cols);
    map<pair<int, int>, set<int>> guesses;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (cells[i][j].state != TARGET){
                continue;
            }

            Cell *hor = find_horizontal(cells, i, j);
            Cell *vert = find_vertical(cells, i, j);

            if (!hor || !vert){
                continue;
            }

            if (!horizontal.count(hor) || !vertical.count(vert)){
                continue;
            }

            set<int> possible;

            for (const auto &comb_hor : horizontal[hor]){
                for (const auto &comb_vert : vertical[vert]){
                    set<int> nums = same(comb_hor, comb_vert);
                    possible.insert(nums.begin(), nums.end());
                }
            }
            guesses[{i, j}] = possible;
        }
    }

    filter_guesses(cells, rows, cols, guesses);

    return guesses;
}