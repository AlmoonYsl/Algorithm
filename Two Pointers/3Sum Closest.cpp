/**
 * leetcode no.16
 * 
 */
int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int closet = nums[0] + nums[1] + nums[2];
    int len = nums.size();
    for (int i = 0; i < len - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int p = i + 1;
        int q = len - 1;
        while (p < q) {
            int sum = nums[i] + nums[p] + nums[q];
            if (abs(closet - target) > abs(sum - target)) {
                closet = sum;
            }
            if (sum < target) {
                p++;
            } else if (sum > target) {
                q--;
            } else {
                return target;
            }
        }
    }
    return closet;
}