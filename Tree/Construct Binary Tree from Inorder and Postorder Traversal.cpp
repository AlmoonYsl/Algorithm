/**
 * leetcode no.106
 */
 
TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2) {
    if (l1 > r1) return nullptr;
    auto *node = new TreeNode(postorder[r2]);
    int r = l1;
    while (r <= r1 && inorder[r] != postorder[r2]) ++r;
    int d = r - l1;
    node->left = dfs(inorder, postorder, l1, r - 1, l2, l2 + d - 1);
    node->right = dfs(inorder, postorder, r + 1, r1, l2 + d, r2 - 1);
    return node;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode *root = dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    return root;
}