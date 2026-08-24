class Solution {
public:

    bool solve(vector<double> nums) {

        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < 1e-6;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {

                vector<double> remaining;

                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        remaining.push_back(nums[k]);
                }

                vector<double> values;

                values.push_back(nums[i] + nums[j]);
                values.push_back(nums[i] - nums[j]);
                values.push_back(nums[j] - nums[i]);
                values.push_back(nums[i] * nums[j]);

                if (abs(nums[j]) > 1e-6)
                    values.push_back(nums[i] / nums[j]);

                if (abs(nums[i]) > 1e-6)
                    values.push_back(nums[j] / nums[i]);

                for (double value : values) {

                    remaining.push_back(value);

                    if (solve(remaining))
                        return true;

                    remaining.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {

        vector<double> nums;

        for (int x : cards)
            nums.push_back(x);

        return solve(nums);
    }
};