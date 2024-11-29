#include "../include/base.cpp"

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s;
        for(auto i : nums) s.insert(i);
        for(int i = 0;i<moveFrom.size();i++) {
            s.erase(s.find(moveFrom[i]));
            s.insert(moveTo[i]);
        }

        vector<int> ret;
        for(auto i : s) ret.push_back(i);
        return ret;
    }
};

void runCase1() {
    Solution solver;
    auto nums = vector<int>{1, 6, 7, 8};
    auto from = vector<int>{1,7,2};
    auto to = vector<int>{2,9,5};
    auto ans = vector<int>{5,6,8,9};
    checker.Check(solver.relocateMarbles(nums, from, to), ans);
}

void runCase2() {
    Solution solver;
    auto nums = vector<int>{1,1,3,3};
    auto from = vector<int>{1,3};
    auto to = vector<int>{2,2};
    auto ans = vector<int>{2};
    checker.Check(solver.relocateMarbles(nums, from, to), ans);
}

int main() {
    runCase1();
    runCase2();
    return 0;
}