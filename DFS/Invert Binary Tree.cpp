/**
 * leetcode no.226
 */
 
void dfs(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = temp;
    dfs(root->left);
    dfs(root->right);
}

TreeNode* invertTree(TreeNode* root) {
   dfs(root);
   return root;
}