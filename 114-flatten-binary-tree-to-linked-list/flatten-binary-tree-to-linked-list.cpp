class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = NULL;
        root->right = left;

        TreeNode* temp = root;
        while (temp->right) temp = temp->right;

        temp->right = right;
    }
};