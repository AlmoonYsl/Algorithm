/**
 * leetcode no.329
 */
static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int rows, columns;

int dfs(vector< vector<int> > &matrix, int row, int column, vector< vector<int> > &memo) {
    if (memo[row][column] != 0) {
        return memo[row][column];
    }
    memo[row][column]++;
    for (auto dir : dirs) {
        int newRow = row + dir[0], newColumn = column + dir[1];
        if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column]) {
            memo[row][column] = max(memo[row][column], dfs(matrix, newRow, newColumn, memo) + 1);
        }
    }
    return memo[row][column];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    rows = matrix.size();
    columns = matrix[0].size();
    auto memo = vector<vector<int>> (rows, vector<int>(columns));
    int ans = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            ans = max(ans, dfs(matrix, i, j, memo));
        }
    }
    return ans;
}