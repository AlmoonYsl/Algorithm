/**
 * leetcode no.347
 */

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> map;
    priority_queue<pair<int, int>> q;
    for (auto i : nums) map[i]++;
    for (auto p : map) {
        q.push(pair<int, int>(-p.second, p.first));
        if (q.size() > k) q.pop();
    }
    while (k--) {
        res.push_back(q.top().second);
        q.pop();
    }
    return res;
}