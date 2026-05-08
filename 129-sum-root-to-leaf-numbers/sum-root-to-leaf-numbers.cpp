class Solution {
public:
    int sumNumbers(TreeNode* root, int curr = 0) {

        if (!root)
            return 0;

        curr = curr * 10 + root->val;

        if (!root->left && !root->right)
            return curr;

        return sumNumbers(root->left, curr) +
               sumNumbers(root->right, curr);
    }
};