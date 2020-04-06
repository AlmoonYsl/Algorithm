/**
 * leetcode no.29
 * 
 */
int recurse(long a, long b){
    if (a > b) return 0;
    long count = 1;
    long c = b;
    while((c + c) >= a){
        c += c;
        count += count;
    }
    return count + recurse(a-c, b);
}

int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (divisor == -1){
        if(dividend > INT_MIN){
            return -dividend;
        } else{
            return INT_MAX;
        }
    }
    int sign = (dividend > 0) ^ (divisor > 0);
    int a = dividend > 0 ? -dividend : dividend;
    int b = divisor > 0 ? -divisor : divisor;
    if(a > b) return 0;
    long res = recurse(a, b);
    if(sign == 0){
        return res > INT_MAX ? INT_MAX : res;
    } else{
        return -res;
    }
}