/**
 * leetcode no.216
 */

void dfs(int k, int n, int start, vector<vector<int>>& res, vector<int>& path) {
    if (n == 0 && k == 0) {
        res.push_back(path);
        return;
    }
    for (int i = start; i <= 9 && n - i >= 0; ++i) {
        path.push_back(i);
        dfs(k - 1, n - i, i + 1, res, path);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(k, n, 1, res, path);
    return res;
}