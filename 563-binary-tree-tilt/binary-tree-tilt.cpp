class Solution {
public:
    int tilt = 0;

    int dfs(TreeNode* root) {

        if (!root)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        tilt += abs(left - right);

        return left + right + root->val;
    }

    int findTilt(TreeNode* root) {

        dfs(root);
        return tilt;
    }
};