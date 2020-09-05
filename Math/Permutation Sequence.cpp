/**
 * leetcode no.60
 */

string getPermutation(int n, int k) {
    vector<char> chs = {'1','2','3','4','5','6','7','8','9'};
    const int factor[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    string str;
    for(--k; n--; k %= factor[n]) {
        const int i = k / factor[n];
        str.push_back(chs[i]);
        chs.erase(chs.begin() + i);
    }
    return str;
}