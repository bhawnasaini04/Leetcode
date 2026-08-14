class Solution {
public:
    int numDecodings(string s) {

        const long long MOD = 1000000007;

        int n = s.size();

        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        // First character
        if (s[0] == '*')
            dp[1] = 9;
        else if (s[0] != '0')
            dp[1] = 1;

        for (int i = 2; i <= n; i++) {

            char current = s[i - 1];
            char previous = s[i - 2];

            // Decode current character alone
            if (current == '*') {
                dp[i] += 9 * dp[i - 1];
            }
            else if (current != '0') {
                dp[i] += dp[i - 1];
            }

            // Decode previous + current together
            if (previous == '*' && current == '*') {

                // 11 to 19 -> 9 possibilities
                // 21 to 26 -> 6 possibilities
                dp[i] += 15 * dp[i - 2];
            }
            else if (previous == '*') {

                // Previous can be 1 for 10-19
                if (current >= '0' && current <= '6')
                    dp[i] += 2 * dp[i - 2];
                else
                    dp[i] += dp[i - 2];
            }
            else if (current == '*') {

                // Previous = 1 -> 11-19 (9 choices)
                if (previous == '1')
                    dp[i] += 9 * dp[i - 2];

                // Previous = 2 -> 21-26 (6 choices)
                else if (previous == '2')
                    dp[i] += 6 * dp[i - 2];
            }
            else {

                int number =
                    (previous - '0') * 10 +
                    (current - '0');

                if (number >= 10 && number <= 26)
                    dp[i] += dp[i - 2];
            }

            dp[i] %= MOD;
        }

        return dp[n];
    }
};