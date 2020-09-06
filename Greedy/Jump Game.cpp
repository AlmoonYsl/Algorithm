/**
 * leetcode no.55
 */

bool canJump(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) return true;
    int dis = nums[0];
    for (int i = 1; i < len - 1; ++i) {
        if (i <= dis) {
            dis = max(dis, nums[i] + i);
        } else {
            return false;
        }
    }
    return dis >= len - 1;
}