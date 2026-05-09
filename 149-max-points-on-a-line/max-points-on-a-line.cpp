class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;
            int duplicate = 1;

            for (int j = i + 1; j < n; j++) {

                if (points[i] == points[j]) {
                    duplicate++;
                    continue;
                }

                double slope;

                if (points[i][0] == points[j][0])
                    slope = INT_MAX;
                else
                    slope = (double)(points[j][1] - points[i][1]) /
                            (points[j][0] - points[i][0]);

                mp[slope]++;
            }

            int currMax = 0;

            for (auto x : mp)
                currMax = max(currMax, x.second);

            ans = max(ans, currMax + duplicate);
        }

        return ans;
    }
};