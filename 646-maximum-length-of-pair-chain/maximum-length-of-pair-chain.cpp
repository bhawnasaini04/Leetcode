class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        // Sort by ending value
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int count = 0;
        int lastEnd = INT_MIN;

        for (auto& pair : pairs) {

            if (pair[0] > lastEnd) {
                count++;
                lastEnd = pair[1];
            }
        }

        return count;
    }
};