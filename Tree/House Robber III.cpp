/**
 * leetcode no.337
 */
vector<int> tryRob(TreeNode* root) {
    if (root == nullptr) return {0, 0};
    vector<int> left = tryRob(root->left);
    vector<int> right = tryRob(root->right);
    vector<int> res;
    res.push_back(max(left[0], left[1]) + max(right[0], right[1]));
    res.push_back(root->val + left[0] + right[0]);
    return res;
}

int rob(TreeNode* root) {
    vector<int> res = tryRob(root);
    return max(res[0], res[1]);
}