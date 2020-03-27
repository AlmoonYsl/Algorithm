/**
 * leetcode no.20
 * 
 */
bool isValid(string s) {
    int len = s.length();
    if (len % 2 != 0)
        return false;
    stack<char> stack;
    for (int i = 0; i < len; ++i) {
        switch (s[i]){
            case '(':
                stack.push(')');
                break;
            case '{':
                stack.push('}');
                break;
            case '[':
                stack.push(']');
                break;
            default:
                if (stack.empty() || stack.size() > len / 2 || stack.top() != s[i]) return false;
                else stack.pop();
        }
    }
    return stack.empty();
}