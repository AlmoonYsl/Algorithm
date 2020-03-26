/**
 * leetcode no.17
 * 
 */
vector<string> getLetters(int i){
    switch (i){
        case 2:
            return {"a", "b", "c"};
        case 3:
            return {"d", "e", "f"};
        case 4:
            return {"g", "h", "i"};
        case 5:
            return {"j", "k", "l"};
        case 6:
            return {"m", "n", "o"};
        case 7:
            return {"p", "q", "r", "s"};
        case 8:
            return {"t", "u", "v"};
        case 9:
            return {"w", "x", "y", "z"};
        default:
            return {};
    }
}


vector<string> letterCombinations(string* digits, int l, int r) {
    if (l == r)
        return getLetters(digits->at(l) - '0');
    int mid = (l + r) / 2;
    vector<string> v1 = letterCombinations(digits, l, mid);
    vector<string> v2 = letterCombinations(digits, mid + 1, r);
    vector<string> res;
    for (const auto & i : v1) {
        for (const auto & j : v2) {
            res.push_back(i + j);
        }
    }
    return res;
}

vector<string> letterCombinations(string digits) {
    if (digits.empty())
        return {};
    if (digits.length() == 1)
        return getLetters(digits.at(0) - '0');
    int mid = (digits.length() - 1) / 2;
    vector<string> v1 = letterCombinations(&digits, 0, mid);
    vector<string> v2 = letterCombinations(&digits, mid + 1, digits.length() - 1);
    vector<string> res;
    for (const auto & i : v1) {
        for (const auto & j : v2) {
            res.push_back(i + j);
        }
    }
    return res;
}