/**
 * leetcode no.18
 * 
 */
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>>res;
    int len = nums.size();
    if (len < 4) return res;
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < len - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        sum = nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
        if (sum > target) break;
        sum = nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1];
        if (sum < target) continue;
        for (int j = i + 1; j < len - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            sum = nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
            if (sum > target) break;
            sum = nums[i] + nums[j] + nums[len - 2] + nums[len - 1];
            if (sum < target) continue;
            int left = j + 1;
            int right = len - 1;
            while(left < right){
                sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target){
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[++left]);
                    while(left < right && nums[right] == nums[--right]);
                } else if (sum < target){
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }
    return res;
}