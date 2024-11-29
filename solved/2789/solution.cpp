#include "../include/base.cpp"

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long now = nums[nums.size()-1];
        long long ans = now;
        for(int i = nums.size()-2;i>=0;i--) {
            if(now >= nums[i]) {
                now += nums[i];
                ans = max(ans, now);
            } else {
                now = nums[i];
            }
        }
        return max(ans, now);
    }
};

void runCase() {
    Solution solver;
    vector<int> buf = {2, 3, 7, 9, 3};
    checker.Check(solver.maxArrayValue(buf), 21);

    buf = {5, 3, 3};
    checker.Check(solver.maxArrayValue(buf), 11);
}

int main() {
    runCase();
    return 0;
}