#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
using namespace std;

enum states
{
    none,
    target,
    condition
};

class cell
{
public:
    int sum_right;
    int sum_down;
    int number;
    states state;

    cell(int r, int d) : sum_right(r), sum_down(d), number(0), state(condition) {}
    cell(int n = 0) : sum_right(0), sum_down(0), number(0)
    {
        state = (n == 0) ? none : target;
    }

    cell &operator=(const int n[2])
    {
        sum_right = n[0];
        sum_down = n[1];
        state = condition;
        return *this;
    }

    cell &operator=(const int n)
    {
        if (n == 0)
        {
            state = none;
        }
        else
        {
            state = target;
            number = n;
        }
        return *this;
    }
};

void print_row(cell cells[], int cols)
{
    cout << "+";
    for (int j = 0; j < cols; j++)
    {
        cout << "-----+";
    }
    cout << endl;

    cout << "|";
    for (int i = 0; i < cols; i++)
    {
        if (cells[i].state == none)
        {
            cout << "     |";
        }
        else if (cells[i].state == target)
        {
            cout << "  0  |";
        }
        else
        {
            if (cells[i].sum_right > 0)
                cout << " " << setw(2) << cells[i].sum_right << "> |";
            else
                cout << "     |";
        }
    }
    cout << endl;

    cout << "|";
    for (int i = 0; i < cols; i++)
    {
        if (cells[i].state == none || cells[i].state == target)
        {
            cout << "     |";
        }
        else
        {
            if (cells[i].sum_down != 0)
            {
                cout << " " << setw(2) << cells[i].sum_down << "v |";
            }
            else
            {
                cout << "     |";
            }
        }
    }
    cout << endl;
}

void print(cell *cells[], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        print_row(cells[i], cols);
    }
    cout << "+";
    for (int j = 0; j < cols; j++)
    {
        cout << "-----+";
    }
    cout << endl;
}

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

unordered_map<cell*, vector<vector<int>>> generate_horizontal(cell *cells[], int rows, int cols)
{
    unordered_map<cell*, vector<vector<int>>> output;
    vector<int> current_sum;
    vector<vector<int>> result;

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
                    generate(current_sum, 1, d, cells[i][j].sum_right, result);
                    output[&cells[i][j]] = result;
                    result.clear();
                    current_sum.clear();
                }
            }
        }
    }
    return output;
}


unordered_map<cell*, vector<vector<int>>> generate_vertical(cell *cells[], int rows, int cols)
{
    unordered_map<cell*, vector<vector<int>>> output;
    vector<int> current_sum;
    vector<vector<int>> result;

    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < cols; i++)
        {
            if (cells[i][j].state == condition && cells[i][j].sum_down > 0)
            {
                int d = 0;
                int k = i + 1;
                while (k < cols && cells[k][j].state == target)
                {
                    d++;
                    k++;
                }

                if (d > 0)
                {
                    generate(current_sum, 1, d, cells[i][j].sum_down, result);
                    output[&cells[i][j]] = result;
                    result.clear();
                    current_sum.clear();
                }
            }
        }
    }
    return output;
}

int main()
{
    int rows = 10, cols = 10;
    cell *cells[rows] = {
        new cell[cols]{0, {0, 23}, {0, 28}, {0, 22}, {0, 5}, {0, 28}, {0, 28}, 0, {0, 10}, {0, 26}},
        new cell[cols]{{39, 0}, 1, 1, 1, 1, 1, 1, {3, 0}, 1, 1},
        new cell[cols]{{23, 0}, 1, 1, 1, 1, 1, 1, {9, 22}, 1, 1},
        new cell[cols]{{24, 0}, 1, 1, 1, {29, 21}, 1, 1, 1, 1, 1},
        new cell[cols]{{17, 0}, 1, 1, {23, 17}, 1, 1, 1, 1, 1, 1},
        new cell[cols]{0, {0, 10}, {4, 22}, 1, 1, {17, 28}, 1, 1, {0, 23}, {0, 13}},
        new cell[cols]{{39, 0}, 1, 1, 1, 1, 1, 1, {13, 22}, 1, 1},
        new cell[cols]{{26, 0}, 1, 1, 1, 1, 1, {23, 5}, 1, 1, 1},
        new cell[cols]{{11, 0}, 1, 1, {27, 0}, 1, 1, 1, 1, 1, 1},
        new cell[cols]{{3, 0}, 1, 1, {23, 0}, 1, 1, 1, 1, 1, 1}
    };

    print(cells, rows, cols);
    unordered_map<cell*, vector<vector<int>>> comb_hor = generate_horizontal(cells, rows, cols);
    unordered_map<cell*, vector<vector<int>>> comb_vert = generate_vertical(cells, rows, cols);

    vector<vector<int>> comb = comb_vert[&cells[0][1]];

    for (auto &nums: comb) {
        for (int v: nums) {
            cout << v << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
        delete[] cells[i];

    return 0;
}
