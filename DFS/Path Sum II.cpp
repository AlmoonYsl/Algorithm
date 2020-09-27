/**
 * leetcode no.113
 */
 
void dfs(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> &path) {
    if (root == nullptr) return;
    path.push_back(root->val);
    if (sum == root->val && root->left == nullptr && root->right == nullptr) {
        res.push_back(path);
    }
    dfs(root->left, sum - root->val, res, path);
    dfs(root->right, sum - root->val, res, path);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(root, sum, res, path);
    return res;
}