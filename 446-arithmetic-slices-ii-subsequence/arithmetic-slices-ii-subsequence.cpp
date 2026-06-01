class Solution {
public:
    int numberOfArithmeticSlices(
        vector<int>& nums) {

        int n = nums.size();
        long long result = 0;

        vector<
            unordered_map<long long,int>
        > dp(n);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                long long diff =
                    (long long)nums[i]
                    - nums[j];

                int count =
                    dp[j].count(diff)
                    ? dp[j][diff]
                    : 0;

                result += count;

                dp[i][diff] +=
                    count + 1;
            }
        }

        return (int)result;
    }
};