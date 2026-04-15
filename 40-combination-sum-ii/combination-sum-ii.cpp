class Solution {
public:
    void backtrack(int index, vector<int>& candidates, int target,
                   vector<int>& path, vector<vector<int>>& result) {
        
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // Stop if number exceeds target
            if (candidates[i] > target) break;

            // Choose
            path.push_back(candidates[i]);

            // Move forward (i+1 → no reuse)
            backtrack(i + 1, candidates, target - candidates[i], path, result);

            // Backtrack
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        sort(candidates.begin(), candidates.end()); // important

        backtrack(0, candidates, target, path, result);
        return result;
    }
};