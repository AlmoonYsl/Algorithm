/**
 * leetcode no.39
 */

void DFS(int start, int target, vector<vector<int>>& res, vector<int>& path, vector<int>& candidates) {
    if (target == 0) {
        res.push_back(path);
    } else {
        for (int i = start; i < candidates.size(); i++) {
            int num = candidates[i];
            if (target < num) continue;
            path.push_back(num);
            DFS(i, target - num, res, path, candidates);
            path.pop_back();
        }
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> path;
    vector<vector<int>> res;
    DFS(0, target, res, path, candidates);
    return res;
}