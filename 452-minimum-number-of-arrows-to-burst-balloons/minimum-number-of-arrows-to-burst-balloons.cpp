class Solution {
public:
    int findMinArrowShots(
        vector<vector<int>>& points) {

        sort(points.begin(),
             points.end(),
             [](auto& a, auto& b) {
                 return a[1] < b[1];
             });

        int arrows = 1;
        long long end = points[0][1];

        for (auto& p : points) {

            if (p[0] > end) {
                arrows++;
                end = p[1];
            }
        }

        return arrows;
    }
};