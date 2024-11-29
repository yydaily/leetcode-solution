#include "../include/base.cpp"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();

        int index = 2;
        for(int i = 2;i<nums.size();i++) {
            if(nums[i] == nums[index-2]) continue;
            nums[index++] = nums[i];
        }
        nums.resize(index);
        return index;
    }
};

void runCase1() {
    vector<int> input = {1, 1, 1, 2, 2, 3};
    vector<int> target = {1, 1, 2, 2, 3};

    Solution solver;
    solver.removeDuplicates(input);

    checker.Check(input, target);
}

void runCase2() {
    vector<int> input = {0,0,1,1,1,1,2,3,3};
    vector<int> target = {0,0,1,1,2,3,3};

    Solution solver;
    solver.removeDuplicates(input);

    checker.Check(input, target);
}

int main() {
    runCase1();
    runCase2();
    return 0;
}