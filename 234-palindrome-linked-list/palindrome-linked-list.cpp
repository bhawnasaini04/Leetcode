class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode *slow = head, *fast = head;

        // Find middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = NULL;

        while (slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Compare both halves
        while (prev) {
            if (head->val != prev->val)
                return false;

            head = head->next;
            prev = prev->next;
        }

        return true;
    }
};