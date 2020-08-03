/**
 * leetcode no.415
 */
string addStrings(string num1, string num2) {
    string res;
    int cur = 0, i = num1.size()-1, j = num2.size()-1;
    while (i >= 0 || j >= 0 || cur != 0) {
        if (i >= 0) cur += num1[i--] - '0';
        if (j >= 0) cur += num2[j--] - '0';
        res += to_string (cur % 10);
        cur /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}