/**
 * leetcode no.410
 */
int splitArray(vector<int>& nums, int m) {
    int len = nums.size();
    vector<vector<long long>> dp(len + 1, vector<long long>(m + 1, LLONG_MAX));
    vector<long long> sub(len + 1, 0);
    dp[0][0] = 0;
    for (int i = 0; i < len; i++) {
        sub[i + 1] = sub[i] + nums[i];
    }
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= min(i, m); ++j) {
            for (int k = 0; k < i; ++k) {
                dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sub[i] - sub[k]));
            }
        }
    }
    return dp[len][m];
}