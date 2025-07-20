class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to help easily return the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        ListNode* a = list1;
        ListNode* b = list2;

        // Two-pointer approach to merge the lists
        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        // Attach the rest of the remaining list
        if (a) tail->next = a;
        if (b) tail->next = b;

        return dummy.next;
    }
};
