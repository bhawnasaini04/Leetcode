class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int ans = 0;

        int mn = arrays[0].front();
        int mx = arrays[0].back();

        for (int i = 1; i < arrays.size(); i++) {

            int currentMin = arrays[i].front();
            int currentMax = arrays[i].back();

            // Current array's maximum with previous minimum
            ans = max(ans, currentMax - mn);

            // Previous maximum with current array's minimum
            ans = max(ans, mx - currentMin);

            // Update global minimum and maximum
            mn = min(mn, currentMin);
            mx = max(mx, currentMax);
        }

        return ans;
    }
};