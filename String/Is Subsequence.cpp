/**
 * leetcode no.392
 */
bool isSubsequence(string s, string t) {
    if (s.empty()) return true;
    if (s.size() > t.size())
        return false;
    int i = 0, j = 0;
    for (; i < s.size() && j < t.size(); ) {
        if (s[i] != t[j]) {
            j++;
            continue;
        } else {
            i++;
            j++;
            continue;
        }
    }
    return i == s.size() && s[i - 1] == t[j - 1];
}