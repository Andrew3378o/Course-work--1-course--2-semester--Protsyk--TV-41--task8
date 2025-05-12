#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include <set>
using namespace std;

class Group{
public:
    vector<pair<int, int>> members;
    int sum;
    set<int> numbers;

    Group() : sum(0) {}

    void insert(int n){
        numbers.insert(n);
        sum += n;
    }

    void push_back(pair<int, int> p){
        members.push_back(p);
    }

    bool contains(int n){
        return numbers.count(n);
    }

    bool find(pair<int, int> p){
        for (auto &pairs : members){
            if (p == pairs){
                return true;
            }
        }
        return false;
    }

    bool empty(){
        return members.empty();
    }

    void remove(int n){
        numbers.erase(n);
        sum -= n;
    }

    void clear(){
        members.clear();
        numbers.clear();
        sum = 0;
    }
};

#endif