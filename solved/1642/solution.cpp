#include "../include/base.cpp"


class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> now;
        for(int i = 1;i<heights.size();i++) {
            if(heights[i] > heights[i-1]) {
                now.insert(heights[i] - heights[i-1]);
            }

            if(now.size() <= ladders) continue;

            auto small = now.begin();
            if(*small <= bricks) {
                bricks -= *small;
                now.erase(small);
                continue;
            }

            return i-1;
        }
        return heights.size()-1;
    }
};

void runCase1() {
    // heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
    Solution solution;
    vector<int> heights = {4,2,7,6,9,14,12};
    int bricks = 5;
    int ladders = 1;
    int answer = 4;
    checker.Check(solution.furthestBuilding(heights, bricks, ladders), answer);
}

void runCase2() {
    // heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
    Solution solution;
    vector<int> heights = {4,12,2,7,3,18,20,3,19};
    int bricks = 10;
    int ladders = 2;
    int answer = 7;
    checker.Check(solution.furthestBuilding(heights, bricks, ladders), answer);
}

void runCase3() {
    // heights = [14,3,19,3], bricks = 17, ladders = 0
    Solution solution;
    vector<int> heights = {14, 3, 19, 3};
    int bricks = 17;
    int ladders = 0;
    int answer = 3;
    checker.Check(solution.furthestBuilding(heights, bricks, ladders), answer);
}

void runCase4() {
    Solution solution;
    vector<int> heights = {2,7,9,12};
    int bricks = 5;
    int ladders = 1;
    int answer = 3;
    checker.Check(solution.furthestBuilding(heights, bricks, ladders), answer);
}

int main() {
    runCase1();
    runCase2();
    runCase3();
    runCase4();
    return 0;
}