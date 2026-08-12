class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        // If we need to add at depth 1,
        // create a new root.
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);

            newRoot->left = root;

            return newRoot;
        }

        // BFS
        queue<TreeNode*> q;
        q.push(root);

        int currentDepth = 1;

        while (!q.empty()) {

            int size = q.size();

            // We are at the level just before
            // the required depth.
            if (currentDepth == depth - 1) {

                while (size--) {

                    TreeNode* node = q.front();
                    q.pop();

                    // Save old children
                    TreeNode* oldLeft = node->left;
                    TreeNode* oldRight = node->right;

                    // Create new nodes
                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);

                    // Attach old subtrees
                    node->left->left = oldLeft;
                    node->right->right = oldRight;
                }

                return root;
            }

            // Move to next level
            while (size--) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            currentDepth++;
        }

        return root;
    }
};