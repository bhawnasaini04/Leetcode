class Solution {
public:
    vector<int> inorderVals;

    void inorder(TreeNode* root) {

        if (!root)
            return;

        inorder(root->left);
        inorderVals.push_back(root->val);
        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {

        inorder(root);

        int ans = INT_MAX;

        for (int i = 1; i < inorderVals.size(); i++) {

            ans = min(
                ans,
                inorderVals[i] - inorderVals[i - 1]
            );
        }

        return ans;
    }
};