class Solution {
public:
    int findMinDifference(
        vector<string>& timePoints) {

        vector<int> mins;

        for (string &t : timePoints) {

            int h =
                stoi(t.substr(0, 2));

            int m =
                stoi(t.substr(3, 2));

            mins.push_back(
                h * 60 + m
            );
        }

        sort(mins.begin(),
             mins.end());

        int ans = INT_MAX;

        for (int i = 1;
             i < mins.size();
             i++) {

            ans = min(
                ans,
                mins[i] - mins[i - 1]
            );
        }

        ans = min(
            ans,
            1440 - mins.back()
            + mins.front()
        );

        return ans;
    }
};