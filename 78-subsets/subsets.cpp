class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, vector<int>& nums, vector<int>& current) {
        // Every state is a valid subset
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);        // include element
            backtrack(i + 1, nums, current);  // move forward
            current.pop_back();               // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(0, nums, current);
        return result;
    }
};