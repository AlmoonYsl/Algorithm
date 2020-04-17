/**
 * leetcode no.8
 */

int myAtoi(string str) {
    int res = 0;
    int q = 0;
    for (char c : str) {
        if (q == 0 && res == 0 && c == ' ') {
            continue;
        }
        if (q == 0 && c == '-') {
            q = -1;
            continue;
        }
        if (q == 0 && c == '+') {
            q = 1;
            continue;
        }
        if (c >= '0' && c <= '9'){
            if (q == 0){
                q = 1;
            }
            int a = (c - '0') * q;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && a > INT_MAX % 10)){
                return INT_MAX;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && a < INT_MIN % 10)){
                return INT_MIN;
            }
            res = res * 10 + a;
        } else {
            return res;
        }
    }
    return res;
}