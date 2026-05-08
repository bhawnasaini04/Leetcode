class Solution {
public:
    int minCut(string s) {

        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<int> dp(n, INT_MAX);

        for (int end = 0; end < n; end++) {

            for (int start = 0; start <= end; start++) {

                if (s[start] == s[end] &&
                   (end - start <= 2 ||
                    pal[start + 1][end - 1])) {

                    pal[start][end] = true;

                    if (start == 0)
                        dp[end] = 0;
                    else
                        dp[end] = min(dp[end],
                                      dp[start - 1] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};