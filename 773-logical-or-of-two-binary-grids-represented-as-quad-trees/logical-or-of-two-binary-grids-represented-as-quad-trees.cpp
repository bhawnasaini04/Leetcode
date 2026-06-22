class Solution {
public:
    Node* intersect(Node* q1, Node* q2) {

        if (q1->isLeaf)
            return q1->val ? q1 : q2;

        if (q2->isLeaf)
            return q2->val ? q2 : q1;

        Node* root = new Node(
            false,
            false,
            intersect(q1->topLeft, q2->topLeft),
            intersect(q1->topRight, q2->topRight),
            intersect(q1->bottomLeft, q2->bottomLeft),
            intersect(q1->bottomRight, q2->bottomRight)
        );

        if (root->topLeft->isLeaf &&
            root->topRight->isLeaf &&
            root->bottomLeft->isLeaf &&
            root->bottomRight->isLeaf &&
            root->topLeft->val == root->topRight->val &&
            root->topLeft->val == root->bottomLeft->val &&
            root->topLeft->val == root->bottomRight->val) {

            return new Node(
                root->topLeft->val,
                true
            );
        }

        return root;
    }
};