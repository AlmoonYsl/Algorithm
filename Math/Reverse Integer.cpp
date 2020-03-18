/**
 *  leetcode no.7
 */
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int p = 0;
        while(x != 0){
            p = x % 10;
            x = x / 10;
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && p > INT_MAX - INT_MAX / 10)
                return 0;
            if (res < INT_MIN / 10 || res == INT_MIN / 10 && p < INT_MIN - INT_MIN / 10)
                return 0;
            res = res * 10 + p;
        }
        return res;
    }
};