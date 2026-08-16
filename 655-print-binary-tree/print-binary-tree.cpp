class Solution {
public:

    int getHeight(TreeNode* root) {

        if (root == NULL)
            return 0;

        return 1 + max(
            getHeight(root->left),
            getHeight(root->right)
        );
    }

    void fillMatrix(TreeNode* root,
                    vector<vector<string>>& answer,
                    int row,
                    int left,
                    int right) {

        if (root == NULL)
            return;

        int middle = (left + right) / 2;

        answer[row][middle] = to_string(root->val);

        fillMatrix(
            root->left,
            answer,
            row + 1,
            left,
            middle - 1
        );

        fillMatrix(
            root->right,
            answer,
            row + 1,
            middle + 1,
            right
        );
    }

    vector<vector<string>> printTree(TreeNode* root) {

        int height = getHeight(root);

        int rows = height;
        int columns = (1 << height) - 1;

        vector<vector<string>> answer(
            rows,
            vector<string>(columns, "")
        );

        fillMatrix(
            root,
            answer,
            0,
            0,
            columns - 1
        );

        return answer;
    }
};