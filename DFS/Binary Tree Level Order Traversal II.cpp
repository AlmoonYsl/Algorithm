/**
 * leetcode no.107
 */

void recursion(TreeNode* root, int depth, vector<vector<int>> *res) {
    if (root == nullptr) return;
    if (res->size() < depth + 1) {
        vector<int> v = vector<int>();
        res->push_back(v);
    }
    recursion(root->left, depth + 1, res);
    recursion(root->right, depth + 1, res);
    res->at(depth).push_back(root->val);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res = vector<vector<int>>();
    recursion(root, 0, &res);
    reverse(res.begin(), res.end());
    return res;
}