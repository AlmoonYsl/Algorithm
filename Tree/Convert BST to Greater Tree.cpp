/**
 * leetcode no.538
 */
 
int num = 0;

void dfs(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    dfs(root->right);
    num += root->val;
    root->val = num;
    dfs(root->left);
}

TreeNode* convertBST(TreeNode* root) {
    dfs(root);
    return root;
}