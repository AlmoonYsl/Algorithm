/**
 * leetcode no.28
 * 
 */
int strStr(string haystack, string needle) {
    if(haystack.empty() && needle.empty()) {
        return 0;
    } else if(needle.empty()){
        return 0;
    } else if(haystack.length() < needle.length()){
        return -1;
    }
    int p = 0;
    int q = 0;
    int len = needle.length();
    while(q < len && p < haystack.length()){
        if(haystack[p] == needle[q]){
            p++;
            q++;
        } else{
            p -= (q - 1);
            q = 0;
        }
    }
    if (q < len) return -1;
    return p - len;
}