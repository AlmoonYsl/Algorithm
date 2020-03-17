/**
 * leetcode no.5 
 * dp[i][j] = dp[i+1][j-1] & s[i] == s[j]
 * 
 */
string longestPalindrome(string s) {
    int length = s.size();
    int left = 0, max = 1;
    if (length == 0 || length == 1)
        return s;
    vector<vector<bool>> dp(length, vector<bool>(length));
    for (int i = 0; i < length; ++i) {
        dp[i][i] = true;
    }
    for (int i = 0; i < length - 1; ++i) {
        dp[i][i + 1] = s[i] == s[i + 1];
    }
    for (int i = length - 2; i >= 0; --i) {
        for (int j = i + 1; j < length; ++j) {
            if (j != i + 1) {
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            }
            if (dp[i][j] && max < j - i + 1){
                max = j - i + 1;
                left = i;
            }
        }
    }
    return s.substr(left, max);
}