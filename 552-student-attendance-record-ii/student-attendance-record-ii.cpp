class Solution {
public:
    int checkRecord(int n) {

        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(2, vector<long long>(3, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {

            vector<vector<long long>> ndp(2, vector<long long>(3, 0));

            for (int a = 0; a <= 1; a++) {
                for (int l = 0; l <= 2; l++) {

                    long long cur = dp[a][l];

                    ndp[a][0] = (ndp[a][0] + cur) % MOD;

                    if (a == 0)
                        ndp[1][0] = (ndp[1][0] + cur) % MOD;

                    if (l < 2)
                        ndp[a][l + 1] = (ndp[a][l + 1] + cur) % MOD;
                }
            }

            dp = move(ndp);
        }

        long long ans = 0;

        for (int a = 0; a <= 1; a++)
            for (int l = 0; l <= 2; l++)
                ans = (ans + dp[a][l]) % MOD;

        return ans;
    }
};