class Codec {
public:
    void preorder(TreeNode* root,
                  string& s) {
        if (!root) return;

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    TreeNode* build(vector<int>& nums,
                    int& idx,
                    int low,
                    int high) {

        if (idx >= nums.size())
            return nullptr;

        int val = nums[idx];

        if (val < low || val > high)
            return nullptr;

        idx++;

        TreeNode* root =
            new TreeNode(val);

        root->left =
            build(nums, idx, low, val);

        root->right =
            build(nums, idx, val, high);

        return root;
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {

        vector<int> nums;
        string temp;

        stringstream ss(data);

        while (getline(ss, temp, ',')) {
            if (!temp.empty())
                nums.push_back(stoi(temp));
        }

        int idx = 0;

        return build(
            nums,
            idx,
            INT_MIN,
            INT_MAX
        );
    }
};