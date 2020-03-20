/**
 * leetcode no.11
 */

int maxArea(vector<int>& height) {
    int res = 0;
    int p = 0, q = height.size();
    while (p != q){
        int area = min(height[p], height[q]) * (q - p);
        res = max(res, area);
        if (height[p] > height[q]){
            q--;
        } else{
            p++;
        }
    }
    return res;
}