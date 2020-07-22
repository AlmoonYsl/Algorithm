/**
 * leetcode no.48
 */
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tmp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = tmp;
        }
    }
}


void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int temp;
    for(int i = 0; i < n/2; ++i){
        for(int j = i; j < n-i-1; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[n-j-1][i];
            matrix[n-j-1][i] = matrix[n-1-i][n-j-1];
            matrix[n-1-i][n-j-1] = matrix[j][n-1-i];
            matrix[j][n-1-i] = temp;
        }
    }
}