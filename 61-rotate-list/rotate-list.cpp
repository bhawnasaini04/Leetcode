class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length and last node
        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            temp = temp->next;
            len++;
        }

        // Step 2: Make it circular
        temp->next = head;

        // Step 3: Find new tail
        k = k % len;
        int stepsToNewTail = len - k;

        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 4: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};