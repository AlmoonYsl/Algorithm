/**
 * leetcode no.343
 */
int integerBreak(int n) {
    vector <int> dp(n + 1);
    for (int i = 2; i <= n; ++i) {
        int cur_max = 0;
        for (int j = 1; j < i; ++j) {
            cur_max = max(cur_max, max(j * (i - j), j * dp[i - j]));
        }
        dp[i] = cur_max;
    }
    return dp[n];
}