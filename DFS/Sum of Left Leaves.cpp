/**
 * leetcode no.404
 */
 
bool isLeafNode(TreeNode* node) {
    return !node->left && !node->right;
}

int dfs(TreeNode* node) {
    int ans = 0;
    if (node->left) {
        ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
    }
    if (node->right && !isLeafNode(node->right)) {
        ans += dfs(node->right);
    }
    return ans;
}

int sumOfLeftLeaves(TreeNode* root) {
    return root ? dfs(root) : 0;
}