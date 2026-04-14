#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int idx, int target, vector<int>& candidates,
                   vector<int>& current, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0 || idx >= candidates.size())
            return;

        // Pick current element
        current.push_back(candidates[idx]);
        backtrack(idx, target - candidates[idx], candidates, current, result);

        // Backtrack
        current.pop_back();

        // Skip current element
        backtrack(idx + 1, target, candidates, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, target, candidates, current, result);
        return result;
    }
};