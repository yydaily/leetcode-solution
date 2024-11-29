#include "../include/base.cpp"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(vector<TreeNode*> roots) {
        vector<vector<int>> ret;
        if(roots.size() == 0) return ret;

        vector<int> buf;
        vector<TreeNode*> nxt;
        for(auto &i : roots) {
            if(i == nullptr) continue;
            buf.push_back(i->val);
            if(i->left != nullptr) nxt.push_back(i->left);
            if(i->right != nullptr) nxt.push_back(i->right);
        }
        ret = levelOrderBottom(nxt);
        if(!buf.empty()) ret.push_back(buf);
        return ret;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<TreeNode*> roots(1, root);
        return levelOrderBottom(roots);
    }
};

void runCase1() {
    auto root = newTreeNodeStr(3);
    root->left = newTreeNodeStr(9);
    root->right = newTreeNodeStr(20);
    root->right->left = newTreeNodeStr(15);
    root->right->right = newTreeNodeStr(7);

    vector<vector<int>> ans;
    ans.push_back({15, 7});
    ans.push_back({9, 20});
    ans.push_back({3});

    Solution solver;
    auto my = solver.levelOrderBottom(root);

    checker.Check(my, ans);
}

void runCase2() {
    auto root = newTreeNodeStr(1);
    vector<vector<int>> ans;
    ans.push_back({1});

    Solution solver;
    auto my = solver.levelOrderBottom(root);

    checker.Check(my, ans);
}

int main() {
    runCase1();
    runCase2();
    return 0;
}