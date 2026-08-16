class Solution {
public:
    bool findValue(TreeNode* root, int k, unordered_set<int>& values) {

        if (root == NULL)
            return false;

        int required = k - root->val;

        // Required value already exists
        if (values.count(required))
            return true;

        values.insert(root->val);

        return findValue(root->left, k, values) ||
               findValue(root->right, k, values);
    }

    bool findTarget(TreeNode* root, int k) {

        unordered_set<int> values;

        return findValue(root, k, values);
    }
};