#include "../include/base.cpp"

class Solution {
public:
    int minimumOperations(string num, string target) {
        int ret = 0;
        int index = 0;
        for(int i = num.size()-1;i>=0;i--) {
            if(num[i]==target[index]) {
                index++;
                if(index == target.length()) return ret;
                continue;
            }
            ret++;
        }
        return num.length();
    }
    int minimumOperations(string num) {
        int ans =  min(
            min(minimumOperations(num, "00"), minimumOperations(num, "05")),
            min(minimumOperations(num, "52"), minimumOperations(num, "57"))
            );
        for(auto i : num) {
            if(i == '0') {
                ans = min(ans, int(num.length()-1));
            }
        }
        return ans;
    }
};

void runCase1() {
    string input = "2245047";
    int ans = 2;
    Solution solver;
    checker.Check(solver.minimumOperations(input), ans);
}
void runCase2() {
    string input = "2908305";
    int ans = 3;
    Solution solver;
    checker.Check(solver.minimumOperations(input), ans);
}
void runCase3() {
    string input = "10";
    int ans = 1;
    Solution solver;
    checker.Check(solver.minimumOperations(input), ans);
}
int main() {
    runCase1();
    runCase2();
    runCase3();
    return 0;
}