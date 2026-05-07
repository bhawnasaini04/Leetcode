class Solution {
public:
    int maxSum = INT_MIN;

    int maxPathDown(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, maxPathDown(root->left));
        int right = max(0, maxPathDown(root->right));

        maxSum = max(maxSum, left + right + root->val);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxPathDown(root);
        return maxSum;
    }
};