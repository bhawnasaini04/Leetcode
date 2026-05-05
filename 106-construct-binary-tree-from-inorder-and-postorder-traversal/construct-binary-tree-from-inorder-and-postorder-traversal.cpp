class Solution {
public:
    unordered_map<int, int> inMap;
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        postIndex = postorder.size() - 1;
        return helper(postorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& postorder, int left, int right) {
        if (left > right) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inMap[rootVal];

        // important: build right first
        root->right = helper(postorder, inIndex + 1, right);
        root->left = helper(postorder, left, inIndex - 1);

        return root;
    }
};