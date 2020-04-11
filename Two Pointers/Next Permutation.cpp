/**
 * leetcode no.31
 * 
 */
void nextPermutation(vector<int>& nums) {
    int p = nums.size() - 1;
    while(p > 0 && nums[p] <= nums[p - 1]){
        p--;
    }
    reverse(nums.begin() + p, nums.end());
    int q = p;
    p--;
    if (p >= 0) {
        for (; q < nums.size(); ++q) {
            if (nums[q] > nums[p]){
                swap(nums[q], nums[p]);
                break;
            }
        }
    }
}