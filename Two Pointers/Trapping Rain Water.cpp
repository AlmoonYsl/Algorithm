/**
 * leetcode no.42
 */
int trap(vector<int>& height)
{
    if(height.empty())
        return 0;
    int ans = 0;
    int left_max = 0, right_max = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
        if (height[left] < height[right]) {
            left_max <= height[left] ? left_max = height[left] : ans += (left_max - height[left]);
            left++;
        } else {
            right_max <= height[right] ? right_max = height[right] : ans += (right_max - height[right]);
            right--;
        }
    }
    return ans;
}