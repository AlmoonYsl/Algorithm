/**
 * leetcode no.26
 */
int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if (len < 2) return len;
    int j = 0; 
    for (int i = 1; i < len; i++)
        if (nums[j] != nums[i]) nums[++j] = nums[i];
    return ++j;
}