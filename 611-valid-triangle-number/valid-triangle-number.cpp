class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int count = 0;

        // k is the largest side
        for (int k = n - 1; k >= 2; k--) {

            int i = 0;
            int j = k - 1;

            while (i < j) {

                if (nums[i] + nums[j] > nums[k]) {

                    // Every number from i to j-1
                    // can form a triangle with j and k
                    count += j - i;

                    j--;
                }
                else {
                    i++;
                }
            }
        }

        return count;
    }
};