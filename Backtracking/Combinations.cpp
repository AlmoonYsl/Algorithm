/**
 * leetcode no.77
 */
void recursion(vector<int> *temp, vector<vector<int>> *res, int cur, int n, int k) {
    if (temp->size() + (n - cur + 1) < k) {
        return;
    }
    if (temp->size() == k) {
        res->push_back(*temp);
        return;
    }
    temp->push_back(cur);
    recursion(temp, res, cur + 1, n, k);
    temp->pop_back();
    recursion(temp, res, cur + 1, n, k);
}

vector<vector<int>> combine(int n, int k) {
    vector<int> temp;
    vector<vector<int>> res;
    recursion(&temp, &res, 1, n, k);
    return res;
}