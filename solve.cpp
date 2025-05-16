#include "solve.h"
#include "generate.h"
#include "utils.h"
#include "print.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
using namespace std;

long long steps = 0;
static int counter = 1;
auto start_time = chrono::high_resolution_clock::now();

/* ---------------------------------------------------------------------[<]-
 Function: is_board_valid
 Synopsis: Checks if the grid is filled in correctly.
 ---------------------------------------------------------------------[>]-*/
bool is_board_valid(Cell **cells, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int j = 0;
        while (j < cols) {
            if (cells[i][j].state == CONDITION && cells[i][j].sum_right > 0) {
                int target_sum = cells[i][j].sum_right;
                int sum = 0;
                set<int> used;
                j++; 
                
                while (j < cols && cells[i][j].state == TARGET) {
                    int num = cells[i][j].number;
                    if (num != 0) {
                        if (used.count(num)) {
                            return false;
                        }
                        used.insert(num);
                        sum += num;
                    }
                    j++;
                }
                
                bool all_filled = true;
                for (int k = j - 1; k >= 0 && cells[i][k].state == TARGET; k--) {
                    if (cells[i][k].number == 0) {
                        all_filled = false;
                        break;
                    }
                }
                
                if (all_filled && sum != target_sum) {
                    return false;
                }
                
                if (sum > target_sum) {
                    return false;
                }
            } else {
                j++; 
            }
        }
    }
    
    for (int j = 0; j < cols; j++) {
        int i = 0;
        while (i < rows) {
            if (cells[i][j].state == CONDITION && cells[i][j].sum_down > 0) {
                int target_sum = cells[i][j].sum_down;
                int sum = 0;
                set<int> used;
                i++; 
     
                while (i < rows && cells[i][j].state == TARGET) {
                    int num = cells[i][j].number;
                    if (num != 0) {
                        if (used.count(num)) {
                            return false; 
                        }
                        used.insert(num);
                        sum += num;
                    }
                    i++;
                }
                
                bool all_filled = true;
                for (int k = i - 1; k >= 0 && cells[k][j].state == TARGET; k--) {
                    if (cells[k][j].number == 0) {
                        all_filled = false;
                        break;
                    }
                }
                
                if (all_filled && sum != target_sum) {
                    return false;
                }
                
                if (sum > target_sum) {
                    return false;
                }
            } else {
                i++; 
            }
        }
    }
    return true; 
}

/* ---------------------------------------------------------------------[<]-
 Function: is_board_complete
 Synopsis: Checks if the grid is completed.
 ---------------------------------------------------------------------[>]-*/
bool is_board_complete(Cell **cells, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (cells[i][j].state == TARGET && cells[i][j].number == 0) {
                return false;
            }
        }
    }
    return true;
}

/* ---------------------------------------------------------------------[<]-
 Function: find_empty_cell
 Synopsis: Returns true if it is possible to find next target cell.
 ---------------------------------------------------------------------[>]-*/
bool find_empty_cell(Cell **cells, int rows, int cols, int &row, int &col) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (cells[i][j].state == TARGET && cells[i][j].number == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

/* ---------------------------------------------------------------------[<]-
 Function: count_filled_cells
 Synopsis: Returns the number of filled in cells at the current moment.
 ---------------------------------------------------------------------[>]-*/
int count_filled_cells(Cell **cells, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (cells[i][j].state == TARGET && cells[i][j].number != 0) {
                count++;
            }
        }
    }
    return count;
}

/* ---------------------------------------------------------------------[<]-
 Function: count_total_cells
 Synopsis: Returns the number of target cells in the grid.
 ---------------------------------------------------------------------[>]-*/
int count_total_cells(Cell **cells, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (cells[i][j].state == TARGET) {
                count++;
            }
        }
    }
    return count;
}

/* ---------------------------------------------------------------------[<]-
 Function: show_progress
 Synopsis: Shows current progress of filling cells.
 ---------------------------------------------------------------------[>]-*/
void show_progress(int filled, int total) {
    steps++;
    if (steps % 1000 == 0) {
        auto current_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(current_time - start_time).count();

        double ratio = static_cast<double>(filled) / total;

        string color;
        if (ratio > 2.0 / 3.0) {
            color = "\033[32m"; 
        } else if (ratio > 1.0 / 3.0) {
            color = "\033[33m"; 
        } else {
            color = "\033[31m"; 
        }

        string reset = "\033[0m";

        cout << "\r" << color << "Filled: " << filled << "/" << total << reset << " | Elapsed: " << duration / 1000 << " seconds" << flush;
    }
}

/* ---------------------------------------------------------------------[<]-
 Function: solve_helper
 Synopsis: Tries to fill the cells, taking into account the current state of the grid,
 if successful - move forward, otherwise - back.
 ---------------------------------------------------------------------[>]-*/
bool solve_helper(Cell **cells, int rows, int cols, int total_cells, map<pair<int, int>, set<int>> guesses) {
    
    int filled = count_filled_cells(cells, rows, cols);
    show_progress(filled, total_cells);
    
    if (is_board_complete(cells, rows, cols)) {
        return is_board_valid(cells, rows, cols);
    }
    
    int row, col;
    if (!find_empty_cell(cells, rows, cols, row, col)) {
        return true;
    }
    
    for (int num: guesses[{row, col}]) {
        cells[row][col].number = num;
        
        if (is_board_valid(cells, rows, cols)) {
            if (solve_helper(cells, rows, cols, total_cells, guesses)) {
                return true;
            }
        }
        cells[row][col].number = 0;
    }
    return false;
}

/* ---------------------------------------------------------------------[<]-
 Function: solve
 Synopsis: Solves the puzzle and prints the details of the process.
 ---------------------------------------------------------------------[>]-*/
void solve(Cell **cells, int rows, int cols) {
    steps = 0;
    start_time = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (cells[i][j].state == TARGET) {
                cells[i][j].number = 0;
            }
        }
    }
    
    cout << "\nStarting to solve test #" << counter << "..." << endl;
    int total_cells = count_total_cells(cells, rows, cols);
    
    map<pair<int, int>, set<int>> guesses = generate_guesses(cells, rows, cols);
    bool solved = solve_helper(cells, rows, cols, total_cells, guesses);
    
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
    
    if (solved) {
        cout << endl;
        print_title("Test #" + to_string(counter), cols);
        string text = "Solved in " + to_string(steps) + " steps! (" +to_string(duration / 1000) + " seconds)";
        print_title(text, cols);
    } else {
        cout << endl;
        print_title("Test #" + to_string(counter), cols);
        string text = "No solution found after " + to_string(steps) + " steps. (" + to_string(duration / 1000) + " seconds)";
        print_title(text, cols);
    }
    counter++;
}