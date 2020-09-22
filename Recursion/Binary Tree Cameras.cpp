/**
 * leetcode no.968
 */
 
int dfs(TreeNode* root, int* res) {
    if (root == nullptr) return 1;
    int l = dfs(root->left, res);
    int r = dfs(root->right, res);
    if (l == 2 || r == 2) {
        ++(*res);
        return 0;
    } else if (l == 0 || r == 0) {
        return 1;
    } else {
        return 2;
    }
}

int minCameraCover(TreeNode* root) {
    if (root == nullptr) return 0;
    int res = 0;
    if (dfs(root, &res) == 2) {
        ++res;
    }
    return res;
}