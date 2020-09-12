/**
 * leetcode no.637
 */

vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode> queue;
    vector<double> res;
    queue.push(*root);
    while (!queue.empty()) {
        int len = queue.size();
        long long sum = 0;
        for (int i = 0; i < len; ++i) {
            auto n = queue.front();
            queue.pop();
            sum += n.val;
            if (n.left != nullptr) queue.push(*n.left);
            if (n.right != nullptr) queue.push(*n.right);
        }
        res.push_back(1.0 * sum / len);
    }
    return res;
}