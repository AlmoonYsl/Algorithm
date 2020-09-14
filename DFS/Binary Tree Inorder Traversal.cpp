/**
 * leetcode no.94
 */
 
void dfs(TreeNode* root, vector<int>* res) {
    if (root == nullptr) return;
    dfs(root->left, res);
    res->push_back(root->val);
    dfs(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(root, &res);
    return res;
}