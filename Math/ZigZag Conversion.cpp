/**
 * leetcode no.6
 * 
 */

string convert(string s, int numRows) {
    int len = s.size();
    if(numRows == 1)
        return s;
    string res;
    int m = 2 * numRows - 2;
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j + i < len; j += m){
            res += s[j + i];
            if(i != 0 && i != numRows - 1 && j + m - i < len){
                res += s[j + m - i];
            }
        }
    }
    return res;
}
