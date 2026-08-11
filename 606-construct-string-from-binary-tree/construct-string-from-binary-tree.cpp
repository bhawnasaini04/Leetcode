class Solution {
public:

    string tree2str(TreeNode* root) {

        if (root == NULL)
            return "";

        string ans = to_string(root->val);

        // Left child exists
        if (root->left != NULL) {
            ans += "(";
            ans += tree2str(root->left);
            ans += ")";
        }

        // Right child exists
        if (root->right != NULL) {

            // Left child does not exist
            if (root->left == NULL) {
                ans += "()";
            }

            ans += "(";
            ans += tree2str(root->right);
            ans += ")";
        }

        return ans;
    }
};