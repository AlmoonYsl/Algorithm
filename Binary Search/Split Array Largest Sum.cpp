/**
 * leetcode no.410
 */
bool check(vector<int>& nums, long long x, int m) {
    long long sum = 0;
    int cnt = 1;
    for (int num : nums) {
        if (sum + num > x) {
            cnt++;
            sum = num;
        } else {
            sum += num;
        }
    }
    return cnt <= m;
}

int splitArray(vector<int>& nums, int m) {
    long long left = 0, right = 0;
    for (int num : nums) {
        right += num;
        if (left < num) left = num;
    }
    while (left < right) {
        long long mid = (left + right) >> 1;
        if (check(nums, mid, m)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return (int)left;
}