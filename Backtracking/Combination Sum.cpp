/**
 * leetcode no.39
 */

void DFS(int start, int target, vector<vector<int>>& res, vector<int>& path, vector<int>& candidates) {
    if (target == 0) {
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
        path.push_back(candidates[i]);
        DFS(i, target - candidates[i], res, path, candidates);
        path.pop_back();
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> path;
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    DFS(0, target, res, path, candidates);
    return res;
}