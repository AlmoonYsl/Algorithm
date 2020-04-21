/**
 * leetcode no.33
 */
int search(vector<int>& nums, int target) {
    if (nums.empty())
        return  -1;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
            l = mid + 1;
        else
            r = mid;
    }
    return l == r && nums[l] == target ? l : -1;
}