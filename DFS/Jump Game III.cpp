/**
 * leetcode no.1306
 */
bool dfs(vector<int>& arr, int start) {
    if (start < 0 || start >= arr.size() || arr[start] == -1) return false;
    int num = arr[start];
    arr[start] = -1;
    return num == 0 || dfs(arr, start + num) || dfs(arr, start - num);
}

bool canReach(vector<int>& arr, int start) {
    return dfs(arr, start);
}