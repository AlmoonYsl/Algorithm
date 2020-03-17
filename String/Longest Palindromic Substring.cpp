/**
 * leetcode no.5
 * 
 */

int getLength(string *s, int left, int right){
    while (left >= 0 && right < s->length() && s->at(left) == s->at(right)){
        --left;
        ++right;
    }
    return right - left - 1;
}

string longestPalindrome(string s) {
    int length = s.size();
    int maxL = 0;
    int start = 0;
    int end = 0;
    if (length == 0 || length == 1)
        return s;
    for (int i = 0; i < length; ++i) {
        int l1 = getLength(&s, i, i);
        int l2 = getLength(&s, i, i+1);
        maxL = max(max(l1, l2), maxL);
        if (maxL > end - start + 1){
            start = i - (maxL - 1)/ 2;
            end = i + maxL / 2;
        }
    }
    return s.substr(start, maxL);
}