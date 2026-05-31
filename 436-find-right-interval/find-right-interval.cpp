class Solution {
public:
    vector<int> findRightInterval(
        vector<vector<int>>& intervals) {

        int n = intervals.size();

        map<int,int> mp;

        for(int i=0;i<n;i++)
            mp[intervals[i][0]] = i;

        vector<int> result(n);

        for(int i=0;i<n;i++) {

            auto it =
            mp.lower_bound(intervals[i][1]);

            result[i] =
                (it == mp.end())
                ? -1
                : it->second;
        }

        return result;
    }
};