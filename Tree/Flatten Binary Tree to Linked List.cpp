/**
 * leetcode no.114
 */
TreeNode* last = nullptr;
void flatten(TreeNode* root) {
    if (root == nullptr) return;
    flatten(root->right);
    flatten(root->left);
    root->right = last;
    root->left = nullptr;
    last = root;
}