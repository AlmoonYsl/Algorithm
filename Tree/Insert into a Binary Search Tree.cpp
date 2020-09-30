/**
 * leetcode no.701
 */
 
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (root->val < val) {
        root->right = insertIntoBST(root->right, val);
        return root;
    }
    if (root->val > val) {
        root->left = insertIntoBST(root->left, val);
        return root;
    }
    return root;
}