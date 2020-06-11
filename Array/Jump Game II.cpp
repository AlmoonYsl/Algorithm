/**
 * leetcode no.45
 */
int jump(vector<int>& nums) {

    int maxPos = 0, end = 0, step = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i <= maxPos) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end) {
                end = maxPos;
                step++;
            }
            if (end >= nums.size() - 1) break;
        }
    }
    return step;
}