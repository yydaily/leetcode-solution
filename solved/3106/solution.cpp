#include "../include/base.cpp"

class Solution {
public:
    int distance(char a, char b) {
        if(a>b) return distance(b, a);
        return min(b-a, a-b+26);
    }
    string getSmallestString(string s, int k) {
        string ret;
        for(auto i : s) {
            if(k==0) {
                ret += i;
                continue;
            }

            for(char x = 'a'; x<='z';x++) {
                if(distance(x, i) <= k) {
                    ret += x;
                    k-=distance(x, i);
                    break;
                }
            }
        }
        return ret;
    }
};

void runCase() {
    Solution solver;
    checker.Check(solver.getSmallestString("zbbz", 3), string("aaaz"));
    checker.Check(solver.getSmallestString("xaxcd", 4), string("aawcd"));
    checker.Check(solver.getSmallestString("lol", 0), string("lol"));
}

int main() {
    runCase();
    return 0;
}