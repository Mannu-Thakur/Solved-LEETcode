/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int countNodes(ListNode* head) {
        int cnt = 0;
        while (head != nullptr) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;

        int cnt = countNodes(head);

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while (cnt >= k) {
            ListNode* curr = prevGroup->next;
            ListNode* next = curr->next;
            ListNode* first = curr;      
            ListNode* prev = nullptr;

             for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

             prevGroup->next = prev;
            first->next = curr;

             prevGroup = first;

            cnt -= k;
        }

        return dummy->next;
    }
};