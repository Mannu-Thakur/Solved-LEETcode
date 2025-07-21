 

class Solution {
    // Reverses k nodes starting from head
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (k-- && curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;   
    }

public:
    ListNode* swapPairs(ListNode* head) {
        int k = 2;
        if (!head || k == 1) return head;

        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count < k) return head;  
         ListNode* newHead = reverse(head, k);
         head->next = swapPairs(curr);

        return newHead;
    }
};
