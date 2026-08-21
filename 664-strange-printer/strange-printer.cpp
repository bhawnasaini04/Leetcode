class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // One character needs only 1 turn
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Length of substring
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                // Print s[j] separately
                dp[i][j] = dp[i][j - 1] + 1;

                for (int k = i; k < j; k++) {

                    // If same characters
                    if (s[k] == s[j]) {
                        dp[i][j] = min(dp[i][j],
                                       dp[i][k] + dp[k + 1][j - 1]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};