/**
 * leetcode no.257
 */
void dfs(TreeNode* root, string path, vector<string>& paths) {
    if (root != nullptr) {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(path);
        } else {
            path += "->";
            dfs(root->left, path, paths);
            dfs(root->right, path, paths);
        }
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    dfs(root, "", paths);
    return paths;
}