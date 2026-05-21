class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root) return "null,";

        return to_string(root->val)+","+
               serialize(root->left)+
               serialize(root->right);
    }

    TreeNode* buildTree(queue<string>& q){

        string val=q.front();
        q.pop();

        if(val=="null")
            return NULL;

        TreeNode* root=
            new TreeNode(stoi(val));

        root->left=buildTree(q);
        root->right=buildTree(q);

        return root;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);
        string temp;
        queue<string> q;

        while(getline(ss,temp,','))
            q.push(temp);

        return buildTree(q);
    }
};