/**
 * leetcode no.79
 */
 
bool dfs(vector<vector<char>>& board, string& word, int x, int y, int k, vector<vector<int>>& path) {
    if (board[x][y] != word[k]) {
        return false;
    } else if (k == word.length() - 1) {
        return true;
    }
    path[x][y] = true;
    bool r = false;
    if ((x + 1) >= 0 && (x + 1) < board.size() && y >= 0 && y < board[0].size() && !path[x + 1][y]) {
        r = dfs(board, word, x + 1, y, k + 1, path);
    }
    if (!r && (x - 1) >= 0 && (x - 1) < board.size() && y >= 0 && y < board[0].size() &&  !path[x - 1][y]) {
        r = dfs(board, word, x - 1, y, k + 1, path);
    }
    if (!r && x >= 0 && x < board.size() && (y + 1) >= 0 && (y + 1) < board[0].size() &&  !path[x][y + 1]) {
        r = dfs(board, word, x, y + 1, k + 1, path);
    }
    if (!r && x >= 0 && x < board.size() && (y - 1) >= 0 && (y - 1) < board[0].size() && !path[x][y - 1]) {
        r = dfs(board, word, x, y - 1, k + 1, path);
    }
    path[x][y] = false;
    return r;
}

bool exist(vector<vector<char>>& board, string word) {
    int h = board.size(), w = board[0].size();
    vector<vector<int>> path(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (dfs(board, word, i, j, 0, path)) return true;
        }
    }
    return false;
}