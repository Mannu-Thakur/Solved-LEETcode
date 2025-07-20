class Solution {
    int solve(ListNode* head){
        if(!head) return 0;
        int cnt = 0;
        ListNode* curr = head;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        
        int total = solve(head);
        if(n == total) { // Special case: removing the head
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* temp = head;
        ListNode* prev = nullptr;
        int cnt = 0;

        while(cnt < (total - n)){
            prev = temp;  // Store previous node correctly
            temp = temp->next;
            cnt++;
        }

        prev->next = temp->next;
        delete temp;
        return head;
    }
};
