class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {

        long long result = 0;
        int n = nums.size();

        for (int bit = 0; bit < 32; bit++) {

            int ones = 0;

            for (int num : nums) {
                if ((num >> bit) & 1)
                    ones++;
            }

            result += 1LL * ones * (n - ones);
        }

        return result;
    }
};