/**
 * leetcode no.47
 */
void backtrack(vector<vector<int>>& res, vector<int>& output, int begin){
    if (begin == output.size()) {
        res.emplace_back(output);
        return;
    }
    backtrack(res, output, begin + 1);
    for (int i = 0; i < begin; ++i) {
        if (output[i] == output[begin]) break;
        swap(output[i], output[begin]);
        backtrack(res, output, begin + 1);
        swap(output[i], output[begin]);
    }
}


vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    backtrack(res, nums, 0);
    return res;
}