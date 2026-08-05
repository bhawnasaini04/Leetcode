class Solution {
public:
    bool isValidSerialization(string preorder) {

        int slots = 1;

        stringstream ss(preorder);
        string node;

        while (getline(ss, node, ',')) {

            // Every node uses one slot
            slots--;

            if (slots < 0)
                return false;

            // Non-null node creates two new slots
            if (node != "#")
                slots += 2;
        }

        return slots == 0;
    }
};