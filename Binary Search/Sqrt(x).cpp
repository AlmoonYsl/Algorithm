/**
 * leetcode no.39
 */

int mySqrt(int x) {
    int l = 0;
    int r = x;
    int res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        long long d = (long long)mid * mid;
        if (d > x) {
            r = mid - 1;
        } else {
            res = mid;
            l = mid + 1;
        }
    }
    return res;
}