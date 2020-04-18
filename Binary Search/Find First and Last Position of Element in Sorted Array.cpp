/**
 * leetcode no.34
 */
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    int n = nums.size(), l = 0, r = n - 1;
    if (nums.empty() || nums[0] > target || nums[r] < target) return res;
    while(l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    if (nums[l] != target) return res;
    res[0] = l;
    r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] <= target) l = mid + 1;
        else r = mid;
    }
    res[1] = r - 1;
    return res;
}