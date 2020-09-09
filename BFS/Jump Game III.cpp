/**
 * leetcode no.1306
 */
bool canReach(vector<int>& arr, int start) {
    if (arr[start] == 0) {
        return true;
    }
    queue<int> q;
    vector<bool> used(arr.size());
    q.push(start);
    used[start] = true;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        if (arr[n] == 0)
            return true;
        int l = n - arr[n];
        int r = n + arr[n];
        if (l >= 0 && !used[l]) {
            q.push(l);
            used[l] = true;
        }
        if (r < arr.size() && !used[r]) {
            q.push(r);
            used[r] = true;
        }
    }
    return false;
}