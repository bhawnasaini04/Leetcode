class Solution {
public:
    int countNodes(TreeNode* root) {

        if(!root)
            return 0;

        TreeNode* left=root;
        TreeNode* right=root;

        int lh=0,rh=0;

        while(left){
            lh++;
            left=left->left;
        }

        while(right){
            rh++;
            right=right->right;
        }

        if(lh==rh)
            return (1<<lh)-1;

        return 1+
            countNodes(root->left)+
            countNodes(root->right);
    }
};