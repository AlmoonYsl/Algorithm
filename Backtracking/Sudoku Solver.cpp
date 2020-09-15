/**
 * leetcode no.37
 */
 
bool success = false;

bool check(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    int tRow = row / 3;
    int tCol = col / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[tRow * 3 + i][tCol * 3 + j] == num) {
                return false;
            }
        }
    }
    return true;
}

void dfs(vector<vector<char>>& board, int i, int j) {
    if (i == 8 && j == 9) {
        success = true;
        return;
    }
    if (j == 9) {
        ++i;
        j = 0;
    }
    if (board[i][j] == '.') {
        for (int k = 1; k <= 9; ++k) {
            if (check(board, i, j, k + '0')) {
                board[i][j] = k + '0';
                dfs(board, i, j + 1);
                if (success) return;
                board[i][j] = '.';
            }
        }
    } else {
        dfs(board, i, j + 1);
    }
}

void solveSudoku(vector<vector<char>>& board) {
    dfs(board, 0, 0);
}


//---------------------------------------------------------------------------------

bool row[9][9], col[9][9], cell[3][3][9];
bool dfs(vector<vector<char>>& board,int x,int y) {
    if (y == 9) x++, y = 0;
    if (x == 9) return true;
    if (board[x][y] != '.')  return dfs(board, x, y + 1);
    for (int i = 0; i < 9; i++)
        if (!row[x][i] && !col[y][i] && !cell[x/3][y/3][i]) {
            board[x][y] = '1' + i;
            row[x][i] = col[y][i] = cell[x/3][y/3][i] = true;
            if (dfs(board, x, y + 1)) return true;
            board[x][y] = '.';
            row[x][i] = col[y][i] = cell[x/3][y/3][i] = false;
        }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    memset(cell, 0, sizeof cell);

    for (int i = 0; i < 9; ++i)
        for(int j = 0; j < 9; ++j)
            if (board[i][j] != '.') {
                int t = board[i][j] - '1';
                row[i][t] = col[j][t] = cell[i/3][j/3][t] = true;
            }
    dfs(board,0,0);
}