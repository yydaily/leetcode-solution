#include "../include/base.cpp"

class Solution {
public:
    struct poi {
        int distance;
        int index;

        poi(){}
        poi(int a, int b) : distance(a), index(b) {}

        bool operator<(const poi & a) const {
            if(distance != a.distance) return distance < a.distance;
            return index < a.index;
        }
    };
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> sons;
        sons.resize(n);
        for(auto edge : edges) {
            int a = edge[0], b = edge[1], c = edge[2];
            sons[a].push_back(make_pair(b, c));
            sons[b].push_back(make_pair(a, c));
        }

        vector<int>distance(n, 0x3fffffff);
        distance[0] = 0;

        set<poi> s;
        s.insert(poi(0, 0));

        while(!s.empty()) {
            auto now = s.begin();
            if(distance[now->index] < now->distance) {
                s.erase(now);
                continue;
            }

            for(auto son : sons[now->index]) {
                int min_dis_son = now->distance + son.second;
                if(distance[son.first] > min_dis_son && disappear[son.first] > min_dis_son) {
                    distance[son.first] = min_dis_son;
                    s.insert(poi(min_dis_son, son.first));
                }
            }

            s.erase(now);
        }

        for(auto &i : distance) {
            if(i == 0x3fffffff) {
                i = -1;
            }
        }
        return distance;
    }
};

void runCase1() {
    // n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,1,5]
    vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 1}, {0, 2, 4}};
    vector<int> disappear = {1, 1, 5};
    int n = 3;
    Solution solution;
    vector<int> answer = {0, -1, 4};

    checker.Check(solution.minimumTime(n, edges, disappear), answer);
}

void runCase2() {
    // n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,3,5]
    vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 1}, {0, 2, 4}};
    vector<int> disappear = {1, 3, 5};
    int n = 3;
    Solution solution;
    vector<int> answer = {0, 2, 3};

    checker.Check(solution.minimumTime(n, edges, disappear), answer);
}

void runCase3() {
  //输入：n = 2, edges = [[0,1,1]], disappear = [1,1]
  //输出：[0,-1]
    vector<vector<int>> edges = {{0, 1, 1}};
    vector<int> disappear = {1, 1};
    int n = 2;
    Solution solution;
    vector<int> answer = {0, -1};

    checker.Check(solution.minimumTime(n, edges, disappear), answer);
}

int main() {
    runCase1();
    runCase2();
    runCase3();
    return 0;
}