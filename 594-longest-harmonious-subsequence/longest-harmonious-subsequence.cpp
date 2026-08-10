class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int ans = 0;

        for (auto &p : freq) {

            int x = p.first;

            if (freq.count(x + 1)) {
                ans = max(ans, p.second + freq[x + 1]);
            }
        }

        return ans;
    }
};