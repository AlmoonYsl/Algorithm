/**
 * leetcode no.LCP 22
 */
 
int combination(int n, int x) {
    int up = 1, i = x, down = 1;
    while(i--)
    {
        up *= n--;
        down *= x--;
    }
    return up/down;
}

int paintingPlan(int n, int k) {
    if (k < n) return 0;
    if (k == n) return 2*n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) * n - i * j == k) res += combination(n, i) * combination(n, j);
        }
    }
    return res;
}