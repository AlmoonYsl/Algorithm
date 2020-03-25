/**
 * leetcode no.14
 * 
 */
string longestCommonPrefix(vector<string>& strs) {
    int len = strs.size();
    if (strs.empty())
        return "";
    if (len == 1)
        return strs[0];
    sort(strs.begin(), strs.end());
    for (int i = 0; i < min(strs[0].size(), strs[len - 1].size()); ++i) {
        if (strs[0][i] != strs[len - 1][i])
            return strs[0].substr(0, i);
    }
    return strs[0].size() > strs[len - 1].length() ? strs[len-1] : strs[0];

}