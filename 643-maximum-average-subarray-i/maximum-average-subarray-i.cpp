class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int currentSum = 0;

        // Sum of first k elements
        for (int i = 0; i < k; i++) {
            currentSum += nums[i];
        }

        int maxSum = currentSum;

        // Move the window
        for (int i = k; i < nums.size(); i++) {

            currentSum += nums[i];
            currentSum -= nums[i - k];

            maxSum = max(maxSum, currentSum);
        }

        return (double)maxSum / k;
    }
};