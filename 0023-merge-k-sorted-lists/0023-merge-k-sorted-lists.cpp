class Solution {
    ListNode* merge(ListNode* temp, ListNode* head) {
        if (!head) return temp;
        if (!temp) return head;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (temp && head) {
            if (temp->val < head->val) {
                curr->next = temp;
                temp = temp->next;
            } else {
                curr->next = head;
                head = head->next;
            }
            curr = curr->next;
        }

        if (temp) curr->next = temp;
        if (head) curr->next = head;

        ListNode* mergedHead = dummy->next;
        delete dummy;
        return mergedHead;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;

        ListNode* head = lists[0];
        for (int i = 1; i < n; ++i) {
            head = merge(lists[i], head);
        }
        return head;
    }
};
