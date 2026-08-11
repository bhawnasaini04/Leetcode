class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        // If first tree is empty
        if (root1 == NULL)
            return root2;

        // If second tree is empty
        if (root2 == NULL)
            return root1;

        // Add the values
        root1->val += root2->val;

        // Merge left subtrees
        root1->left = mergeTrees(root1->left, root2->left);

        // Merge right subtrees
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};