#include "utils.h"
#include <algorithm>
#include <set>

/* ---------------------------------------------------------------------[<]-
 Function: same
 Synopsis: Returns the set that contains values common for two original vectors.
 ---------------------------------------------------------------------[>]-*/
set<int> same(vector<int> v1, vector<int> v2){
    set<int> output;
    for(int num: v1){
        if(find(v2.begin(), v2.end(), num) != v2.end()){
            output.insert(num);
        }
    }
    return output;
}

/* ---------------------------------------------------------------------[<]-
 Function: find_horizontal
 Synopsis: Returns the pointer to the nearest horizontal conditional cell.
 ---------------------------------------------------------------------[>]-*/
Cell* find_horizontal(Cell **cells, int i, int j){
    for (int k = j - 1; k >= 0; k--){
        if (cells[i][k].state == CONDITION){
            return &cells[i][k];
        }
    }
    return nullptr;
}

/* ---------------------------------------------------------------------[<]-
 Function: find_vertical
 Synopsis: Returns the pointer to the nearest vertical conditional cell.
 ---------------------------------------------------------------------[>]-*/
Cell *find_vertical(Cell **cells, int i, int j){
    for (int k = i - 1; k >= 0; k--){
        if (cells[k][j].state == CONDITION){
            return &cells[k][j];
        }
    }
    return nullptr;
}

/* ---------------------------------------------------------------------[<]-
 Function: filter_guesses
 Synopsis: Filters possible values in each target cell to prevent conflicts.
 ---------------------------------------------------------------------[>]-*/
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
