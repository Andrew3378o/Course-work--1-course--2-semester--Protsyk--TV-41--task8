#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include <set>
using namespace std;

class Group
{
public:
    vector<pair<int, int>> members;
    int sum;
    set<int> numbers;

    void insert(int n)
    {
        numbers.insert(n);
    }

    void push_back(pair<int, int> p)
    {
        members.push_back(p);
    }

    bool count(int n)
    {
        return numbers.count(n);
    }

    void clear()
    {
        members.clear();
        numbers.clear();
        sum = 0;
    }
};

#endif