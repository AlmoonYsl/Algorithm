/**
 * leetcode no.1528
 */
string restoreString(string s, vector<int>& indices) {
    int i = 0;
    while (i < s.size()) {
        if (i != indices[i]){
            swap(s[i], s[indices[i]]);
            swap(indices[i], indices[indices[i]]);
            continue;
        }
        i++;
    }
    return s;
}