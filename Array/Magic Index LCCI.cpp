/**
 * leetcode no.面试.08.03
 */
int getAnswer(vector<int>& nums, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    int answer = getAnswer(nums, left, mid - 1);
    if (answer != -1) return answer;
    if (mid == nums[mid]) return mid;
    return getAnswer(nums, mid + 1, right);
}

int findMagicIndex(vector<int>& nums) {
    return getAnswer(nums, 0, nums.size() - 1);
}