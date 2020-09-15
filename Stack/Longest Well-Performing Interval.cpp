/**
 * leetcode no.1124
 */

int longestWPI(vector<int>& hours) {
    int n = hours.size();
    int res = 0;
    vector<int> sum(n + 1,0);

    for (int i = 0;i < n; ++i){
        sum[i + 1] = sum[i] + (hours[i] > 8 ? 1 : (-1));
    }
    stack<int> stack;
    stack.push(0);
    for (int j = 1; j < n; ++j) {
        if (sum[stack.top()] > sum[j]) {
            stack.push(j);
        }
    }
    for (int k = n - 1; k > 0; --k) {
        while (!stack.empty() && sum[stack.top()] < sum[k]) {
            res = max(res, k - stack.top());
            stack.pop();
        }
    }
    return res;
}