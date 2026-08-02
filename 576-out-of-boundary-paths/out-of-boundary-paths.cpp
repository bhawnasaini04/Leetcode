class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int m, int n, int maxMove, int row, int col,
              vector<vector<vector<int>>>& dp) {

        // Ball goes out of boundary
        if (row < 0 || row >= m || col < 0 || col >= n)
            return 1;

        // No moves left
        if (maxMove == 0)
            return 0;

        if (dp[row][col][maxMove] != -1)
            return dp[row][col][maxMove];

        long up = solve(m, n, maxMove - 1, row - 1, col, dp);
        long down = solve(m, n, maxMove - 1, row + 1, col, dp);
        long left = solve(m, n, maxMove - 1, row, col - 1, dp);
        long right = solve(m, n, maxMove - 1, row, col + 1, dp);

        return dp[row][col][maxMove] =
            (up + down + left + right) % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(maxMove + 1, -1))
        );

        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};