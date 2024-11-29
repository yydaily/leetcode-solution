#include "../include/base.cpp"

class Solution {
public:
    vector<vector<int>> pathTarget(TreeNode* root, int target, vector<int> prefix) {
        if(isLeaf(root)) {
            if(target == root->val) {
                prefix.push_back(target);
                return vector<vector<int>>(1, prefix);
            }
            return vector<vector<int>>{};
        }

        vector<vector<int>> ret;
        prefix.push_back(root->val);
        target -= root->val;
        if(root->left != nullptr) {
            for(auto i : pathTarget(root->left, target, prefix)) {
                ret.push_back(i);
            }
        }
        if(root->right != nullptr) {
            for(auto i : pathTarget(root->right, target, prefix)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        if(root == nullptr) {
            return vector<vector<int>>{};
        }
        return pathTarget(root, target, vector<int>{});
    }
};

void runCase1() {
    auto root = newTreeNodeStr(5);

    root->left = newTreeNodeStr(4);
    root->left->left = newTreeNodeStr(11);
    root->left->left->left = newTreeNodeStr(7);
    root->left->left->right = newTreeNodeStr(2);

    root->right = newTreeNodeStr(8);
    root->right->left = newTreeNodeStr(13);
    root->right->right = newTreeNodeStr(4);
    root->right->right->left = newTreeNodeStr(5);
    root->right->right->right = newTreeNodeStr(1);

    Solution solver;
    int target = 22;

    vector<vector<int>> ans;
    ans.push_back({5,4,11,2});
    ans.push_back({5,8,4, 5});

    checker.Check(solver.pathTarget(root,target), ans);
}

void runCase2() {
    auto root = newTreeNodeStr(1);
    root->left = newTreeNodeStr(2);
    root->right = newTreeNodeStr(3);
    Solution solver;
    int target = 5;

    vector<vector<int>> ans;

    checker.Check(solver.pathTarget(root, target), ans);
}

void runCase3() {
    auto root = newTreeNodeStr(1);
    root->left = newTreeNodeStr(2);

    Solution solver;
    int target = 0;

    vector<vector<int>> ans;

    checker.Check(solver.pathTarget(root, target), ans);
}

int main() {
    runCase1();
    runCase2();
    runCase3();
    return 0;
}