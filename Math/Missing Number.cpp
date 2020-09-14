/**
 * leetcode no.268
 */

int missingNumber(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    int len = nums.size();
    int res = (len * len + len) / 2 - sum;
    return res;
}