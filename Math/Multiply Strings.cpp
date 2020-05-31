/**
 * leetcode no.43
 */
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    int n1 = num1.size();
    int n2 = num2.size();
    string res(n1 + n2,'0');
    for (int i = n2 - 1; i >= 0; i--){
        for (int j = n1 - 1; j >= 0; j--){
            int temp = (res[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
            res[i + j + 1] = temp % 10;
            res[i + j] += temp / 10 + '0';
        }
    }

    for (int i = 0; i < n1 + n2; i++){
        if (res[i] != '0') return res.substr(i);
    }
    return "0";
}