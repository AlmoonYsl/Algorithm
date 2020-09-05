/**
 * leetcode no.486
 */

bool PredictTheWinner(vector<int>& nums) {
    int len = nums.size();
    int dp[len];
    for (int i = 0; i < len; ++i) {
        dp[i] = nums[i];
    }
    for (int i = len - 2; i >= 0; i--) {
        for (int j = i + 1; j < len; j++) {
            dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
    }
    return dp[len - 1] >= 0;
}