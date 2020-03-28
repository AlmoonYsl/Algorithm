/**
 * leetcode no.22
 * 
 */
void generate(vector<string>* v, int t, int m, string s, int n){
    if (s.length() == 2 * n && s[2 * n - 1] != '(') v->push_back(s);
    if (t < 0){
        generate(v, t + 1, m, s + ')', n);
    }
    if (t <= 0 && m < n){
        generate(v, t - 1, m + 1, s + '(', n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n == 0) return res;
    if (n == 1) return {"()"};
    string s = "(";
    generate(&res, -1, 1, s, n);
    return res;
}