class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, int n, int k, vector<int>& current) {
        // If the combination is complete
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++) {
            current.push_back(i);              // choose
            backtrack(i + 1, n, k, current);   // explore
            current.pop_back();                // un-choose (backtrack)
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        backtrack(1, n, k, current);
        return result;
    }
};