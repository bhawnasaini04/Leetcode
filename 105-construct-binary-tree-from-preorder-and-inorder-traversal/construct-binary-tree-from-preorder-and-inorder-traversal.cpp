class Solution {
public:
    unordered_map<int, int> inMap;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return helper(preorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int left, int right) {
        if (left > right) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inMap[rootVal];

        root->left = helper(preorder, left, inIndex - 1);
        root->right = helper(preorder, inIndex + 1, right);

        return root;
    }
};