class Solution {
public:
    unordered_map<string, int> count;
    vector<TreeNode*> answer;

    string findSubtree(TreeNode* root) {

        if (root == NULL)
            return "#";

        string left = findSubtree(root->left);
        string right = findSubtree(root->right);

        string current =
            to_string(root->val) + "," + left + "," + right;

        count[current]++;

        // Add only the first occurrence
        if (count[current] == 2) {
            answer.push_back(root);
        }

        return current;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        findSubtree(root);

        return answer;
    }
};