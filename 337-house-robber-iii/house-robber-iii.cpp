class Solution {
public:
    pair<int,int> dfs(TreeNode* root) {
        if (!root)
            return {0,0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Rob current node
        int rob = root->val + left.second + right.second;

        // Do not rob current node
        int notRob = max(left.first, left.second) +
                     max(right.first, right.second);

        return {rob, notRob};
    }

    int rob(TreeNode* root) {
        auto ans = dfs(root);

        return max(ans.first, ans.second);
    }
};