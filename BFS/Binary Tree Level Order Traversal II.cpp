/**
 * leetcode no.107
 */

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res = vector<vector<int>>();
    if (!root) return res;
    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        vector<int> v = vector<int>();
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = queue.front();
            queue.pop();
            v.push_back(node->val);
            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
        }
        res.push_back(v);
    }
    reverse(res.begin(), res.end());
    return res;
}