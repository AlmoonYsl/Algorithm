/**
 * leetcode no.38
 * 
 */
string countAndSay(int n) {
    if (n == 1)
        return "1";
    string res = "1";
    char num = '1';
    string temp;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < res.length() - 1; ++j) {
            if (res[j] == res[j + 1]){
                num++;
            } else{
                temp += num;
                temp += res[j];
                num = '1';
            }
        }
        temp += num;
        temp += res[res.length() - 1];
        res = temp;
        temp = "";
        num = '1';
    }
    return res;
}