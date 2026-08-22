class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {

        if (root == NULL)
            return NULL;

        // Root value is smaller than low
        if (root->val < low)
            return trimBST(root->right, low, high);

        // Root value is greater than high
        if (root->val > high)
            return trimBST(root->left, low, high);

        // Root is within range
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};