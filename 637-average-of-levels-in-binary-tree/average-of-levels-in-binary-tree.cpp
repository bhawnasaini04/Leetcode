class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> answer;

        if (root == NULL)
            return answer;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int levelSize = q.size();
            double sum = 0;

            for (int i = 0; i < levelSize; i++) {

                TreeNode* currentNode = q.front();
                q.pop();

                sum += currentNode->val;

                if (currentNode->left != NULL)
                    q.push(currentNode->left);

                if (currentNode->right != NULL)
                    q.push(currentNode->right);
            }

            double average = sum / levelSize;

            answer.push_back(average);
        }

        return answer;
    }
};