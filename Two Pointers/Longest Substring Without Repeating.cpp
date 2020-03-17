/**
 *  leetcode no.3
 */
int lengthOfLongestSubstring(string s) {
    int start = 0, end = 0, length = 0, max = 0;
    while (end < s.length())
    {
        char c = s[end];
        for (int i = start; i < end; i++)
        {
            if (c == s[i])
            {
                start = i + 1;
                break;
            }
        }
        end++;
        length = end - start;
        max = max > length ? max : length;
    }
    return max;
}
int lengthOfLongestSubstring2(string s) {
    unordered_map<char, int> hash_map;
    int max = 0;
    int length = 0;
    for (int start = 0, end = 0; end < s.length(); ++end) {
        if (hash_map.find(s[end]) != hash_map.end() && hash_map[s[end]] >= start){
            start = hash_map[s[end]] + 1;
        }
        hash_map[s[end]] = end;
        length = end - start + 1;
        max = length > max ? length : max;
    }
    return max;
}


