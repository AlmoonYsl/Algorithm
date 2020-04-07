/**
 * leetcode no.35
 * 
 */
int searchInsert(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size();
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
}