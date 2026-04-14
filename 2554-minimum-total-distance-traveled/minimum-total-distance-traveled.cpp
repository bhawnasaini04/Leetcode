#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());

        int n = robots.size();
        int m = factories.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));

        // Base case: no robots → 0 distance
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int j = 1; j <= m; j++) {
            int pos = factories[j - 1][0];
            int cap = factories[j - 1][1];

            for (int i = 0; i <= n; i++) {
                // Option 1: skip this factory
                dp[i][j] = dp[i][j - 1];

                long long cost = 0;

                // Option 2: assign k robots to this factory
                for (int k = 1; k <= cap && i - k >= 0; k++) {
                    cost += abs(robots[i - k] - pos);

                    if (dp[i - k][j - 1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j],
                                       dp[i - k][j - 1] + cost);
                    }
                }
            }
        }

        return dp[n][m];
    }
};