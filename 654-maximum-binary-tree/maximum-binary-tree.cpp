class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int left, int right) {

        if (left > right)
            return NULL;

        // Find maximum element
        int maxIndex = left;

        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Create root
        TreeNode* root = new TreeNode(nums[maxIndex]);

        // Build left subtree
        root->left = buildTree(nums, left, maxIndex - 1);

        // Build right subtree
        root->right = buildTree(nums, maxIndex + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};