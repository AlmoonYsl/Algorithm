/**
 * leetcode no.27
 * 
 */
int removeElement(vector<int>& nums, int val) {
    if(nums.empty()) return 0;
    int p = 0;
    int q = nums.size();
    while(p < q){
        if (nums[p] == val){
            nums[p] = nums[q - 1];
            q--;
        } else{
           p++;
        }
    }
    return q;
}