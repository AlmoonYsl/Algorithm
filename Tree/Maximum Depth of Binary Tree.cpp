/**
 * leetcode no.104
 */
int res;

void dfs(TreeNode* root, int cur) {
    if (root == nullptr) {
        if (cur > res) {
            res = cur;
        }
    } else {
        ++cur;
        dfs(root->left, cur);
        dfs(root->right, cur);
    }
}

int maxDepth(TreeNode* root) {
    dfs(root, 0);
    return res;
}




int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
}