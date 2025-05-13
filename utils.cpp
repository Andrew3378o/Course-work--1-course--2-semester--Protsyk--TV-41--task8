#include "utils.h"
#include <algorithm>
#include <set>

set<int> same(vector<int> v1, vector<int> v2){
    set<int> output;
    for(int num: v1){
        if(find(v2.begin(), v2.end(), num) != v2.end()){
            output.insert(num);
        }
    }
    return output;
}

Cell* find_horizontal(Cell **cells, int i, int j){
    for (int k = j - 1; k >= 0; k--){
        if (cells[i][k].state == CONDITION){
            return &cells[i][k];
        }
    }
    return nullptr;
}

Cell *find_vertical(Cell **cells, int i, int j){
    for (int k = i - 1; k >= 0; k--){
        if (cells[k][j].state == CONDITION){
            return &cells[k][j];
        }
    }
    return nullptr;
}

void filter_guesses(Cell **cells, int rows, int cols, map<pair<int, int>, set<int>> &guesses) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (cells[i][j].state != TARGET) continue;

                auto it = guesses.find({i, j});
                if (it != guesses.end() && it->second.size() == 1) {
                    int to_delete = *it->second.begin(); 

                    int k;

                    k = j + 1;
                    while (k < cols && cells[i][k].state == TARGET) {
                        if (guesses[{i, k}].erase(to_delete)) changed = true;
                        k++;
                    }

                    k = j - 1;
                    while (k >= 0 && cells[i][k].state == TARGET) {
                        if (guesses[{i, k}].erase(to_delete)) changed = true;
                        k--;
                    }

                    k = i + 1;
                    while (k < rows && cells[k][j].state == TARGET) {
                        if (guesses[{k, j}].erase(to_delete)) changed = true;
                        k++;
                    }

                    k = i - 1;
                    while (k >= 0 && cells[k][j].state == TARGET) {
                        if (guesses[{k, j}].erase(to_delete)) changed = true;
                        k--;
                    }
                }
            }
        }
    }
}
