struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode _TreeNode_buf[1000];
int _TreeNode_idx = -1;

TreeNode* newTreeNodeStr(int value) {
    ++_TreeNode_idx;
    _TreeNode_buf[_TreeNode_idx].val = value;
    _TreeNode_buf[_TreeNode_idx].left = nullptr;
    _TreeNode_buf[_TreeNode_idx].right = nullptr;
    return &_TreeNode_buf[_TreeNode_idx];
}

bool isLeaf(TreeNode* root) {
    return root != nullptr && root->left == nullptr && root->right == nullptr;
}