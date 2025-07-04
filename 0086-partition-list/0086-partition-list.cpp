class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;

        // Dummy heads
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterEqualHead = new ListNode(0);

        // Tails
        ListNode* less = lessHead;
        ListNode* greaterEqual = greaterEqualHead;

        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greaterEqual->next = head;
                greaterEqual = greaterEqual->next;
            }
            head = head->next;
        }

        // Terminate list
        greaterEqual->next = nullptr;

        // Connect two partitions
        less->next = greaterEqualHead->next;

        ListNode* result = lessHead->next;
        delete lessHead;
        delete greaterEqualHead;

        return result;
    }
};
