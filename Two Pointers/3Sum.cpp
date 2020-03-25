/**
 * leetcode no.15
 * 
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>>res;
    int len = nums.size();
    for(int i = 0; i < len - 2; i++){
        if(nums[i] > 0)
            break;
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        int p = i+1;
        int q = len-1;
        while(p < q){
            int sum = nums[i] + nums[p] + nums[q];
            if(sum < 0){
                p++;
            }else if (sum > 0){
                q--;
            }else{
                res.push_back({nums[i], nums[p], nums[q]});
                while(p < q && nums[p] == nums[++p]);
                while(p < q && nums[q] == nums[--q]);
            }
        }
    }
    return res;
}