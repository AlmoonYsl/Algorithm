/**
 * leetcode no.36
 */
bool isValidSudoku(vector<vector<char>>& board) {
    int a[9][9] = {0};
    int b[9][9] = {0};
    int c[9][9] = {0};
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] != '.') {
                if(( ++a[board[i][j]-'1'][i] > 1) ||
                   (++b[board[i][j]-'1'][j] > 1) ||
                   (++c[board[i][j]-'1'][(i/3)*3 + j/3] > 1)) {
                    return false;
                }
            }
        }
    }
    return true;
}