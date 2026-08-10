class Solution {
public:
    int findIntegers(int n) {

        vector<int> dp(32, 0);

        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < 32; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int ans = 0;
        int prevBit = 0;

        for (int i = 30; i >= 0; i--) {

            if (n & (1 << i)) {

                ans += dp[i];

                // Found consecutive 1s
                if (prevBit == 1) {
                    return ans;
                }

                prevBit = 1;
            }
            else {
                prevBit = 0;
            }
        }

        // Include n itself
        return ans + 1;
    }
};