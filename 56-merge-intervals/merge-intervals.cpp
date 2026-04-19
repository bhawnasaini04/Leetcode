#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        if (intervals.empty()) return result;

        // Sort by starting time
        sort(intervals.begin(), intervals.end());

        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                // Overlapping → merge
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // No overlap → add new interval
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};