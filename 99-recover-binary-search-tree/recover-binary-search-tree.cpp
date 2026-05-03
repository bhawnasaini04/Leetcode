class Solution {
public:
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    }
};