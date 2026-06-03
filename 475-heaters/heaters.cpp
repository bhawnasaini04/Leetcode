class Solution {
public:
    int findRadius(vector<int>& houses,
                   vector<int>& heaters) {

        sort(heaters.begin(), heaters.end());

        int radius = 0;

        for (int house : houses) {

            auto it = lower_bound(
                heaters.begin(),
                heaters.end(),
                house
            );

            int rightDist = (it == heaters.end())
                ? INT_MAX
                : *it - house;

            int leftDist = (it == heaters.begin())
                ? INT_MAX
                : house - *prev(it);

            radius = max(
                radius,
                min(leftDist, rightDist)
            );
        }

        return radius;
    }
};