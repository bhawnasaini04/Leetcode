class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }

    void dfs(TreeNode* node, int sum) {
        if (!node) return;

        path.push_back(node->val);

        if (!node->left && !node->right && sum == node->val) {
            result.push_back(path);
        } else {
            dfs(node->left, sum - node->val);
            dfs(node->right, sum - node->val);
        }

        path.pop_back(); // backtrack
    }
};