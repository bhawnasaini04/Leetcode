class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;

        // First k+1 numbers
        int left = 1;
        int right = k + 1;

        while (left <= right) {
            if (left <= right) {
                ans.push_back(left);
                left++;
            }

            if (left <= right) {
                ans.push_back(right);
                right--;
            }
        }

        // Add remaining numbers
        for (int i = k + 2; i <= n; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};