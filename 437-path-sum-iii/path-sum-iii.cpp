class Solution {
public:
    int dfs(TreeNode* root,
            long long currSum,
            int target,
            unordered_map<long long,int>& prefix) {

        if(!root)
            return 0;

        currSum += root->val;

        int count =
            prefix[currSum - target];

        prefix[currSum]++;

        count += dfs(
            root->left,
            currSum,
            target,
            prefix
        );

        count += dfs(
            root->right,
            currSum,
            target,
            prefix
        );

        prefix[currSum]--;

        return count;
    }

    int pathSum(TreeNode* root,
                int targetSum) {

        unordered_map<long long,int> prefix;
        prefix[0] = 1;

        return dfs(
            root,
            0,
            targetSum,
            prefix
        );
    }
};