/**
 * leetcode no.10
 */

bool isMatch(string s, string p) {
    return isMatch(s.c_str(), p.c_str());
}

bool isMatch(const char *s, const char* p){
    if (*p == 0)
        return *s == 0;
    bool f = *s && (*s == *p || *p == '.');
    if (*(p + 1) == '*'){
        return isMatch(s, p + 2) || (f && isMatch(++s, p));
    } else {
        return f && isMatch(++s, ++p);
    }
}