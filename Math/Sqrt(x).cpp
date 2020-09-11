/**
 * leetcode no.39
 */

double NtSqrt(const double num) {
    if (num < 0) {
        return -1;
    } else {
        double root = num;
        while (abs(num - root * root) >= 0.5) {
            root = (num / root + root) / 2.0;
        }
        return root;
    }
}

int mySqrt(int x) {
    return NtSqrt(x);
}