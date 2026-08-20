class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int answer = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();

            unsigned long long first = q.front().second;
            unsigned long long last = first;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                unsigned long long pos = q.front().second;

                q.pop();

                // Normalize position
                pos = pos - first;

                if (i == size - 1) {
                    last = pos;
                }

                if (node->left != NULL) {
                    q.push({node->left, 2 * pos});
                }

                if (node->right != NULL) {
                    q.push({node->right, 2 * pos + 1});
                }
            }

            int width = last + 1;
            answer = max(answer, width);
        }

        return answer;
    }
};