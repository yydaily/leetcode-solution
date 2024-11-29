#include "../include/base.cpp"

class Solution {
public:
    map<int, int> cal(vector<int> &nums, int minm) {
        // nums[j] - nums[i] >= minm
        map<int, int> cnt[nums.size()];
        cnt[0][1] = 1;

        for(int i = 1;i<nums.size();i++) {
            for(int j = 0;j<i;j++) {
                if(nums[i] - nums[j] >= minm) {
                    for(auto pair : cnt[j]) {
                        int &x = cnt[i][pair.first+1];
                        x = nt.add(x, pair.second);
                    }
                }
            }
        }

        map<int, int> ret;
        for(int i = 0;i<nums.size();i++) {
            for(auto k : cnt[i]) {
                ret[k.first] = nt.add(ret[k.first], k.second);
            }
        }
        return ret;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ret = 0;
        for(int i = 0;i<nums.size();i++) {
            for(int j = i+1;j<nums.size();j++) {
                int target = nums[j] - nums[i];

                vector<int> ll;
                for(int k = i;k>=0;k--) {
                    ll.push_back(nums[i] - nums[k]);
                }
                auto m1 = cal(ll, target);

                vector<int> rr;
                for(int k = j;k<nums.size();k++) {
                    rr.push_back(nums[k] - nums[j]);
                }

                auto m2 = cal(rr, target+1);

                for(auto p : m1) {
                    ret = nt.add(ret, nt.mul(p.second, m2[k-p.first], target));
                }
            }
        }
        return ret;
    }
};

void runCase1() {
    Solution solver;
    vector<int> nums = {1,2,3,4};
    int k = 3;
    int ans = 4;

    checker.Check(solver.sumOfPowers(nums, k), ans);
}

void runCase2() {
    Solution solver;
    vector<int> nums = {2,2};
    int k = 2;
    int ans = 0;

    checker.Check(solver.sumOfPowers(nums, k), ans);
}

void runCase3() {
    Solution solver;
    vector<int> nums = {4,3,-1};
    int k = 2;
    int ans = 10;

    checker.Check(solver.sumOfPowers(nums, k), ans);
}

int main() {
    runCase1();
    runCase2();
    runCase3();
    return 0;
}