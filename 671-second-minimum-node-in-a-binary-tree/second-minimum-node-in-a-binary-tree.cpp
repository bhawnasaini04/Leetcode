class Solution {
public:
    long long first = -1;
    long long second = -1;

    void findSecond(TreeNode* root) {
        if (root == NULL)
            return;

        if (first == -1) {
            first = root->val;
        }
        else if (root->val > first) {
            if (second == -1 || root->val < second)
                second = root->val;
        }

        findSecond(root->left);
        findSecond(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        findSecond(root);

        return second;
    }
};