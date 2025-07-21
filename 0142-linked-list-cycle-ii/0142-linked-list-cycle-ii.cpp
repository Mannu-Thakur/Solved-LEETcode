/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* find(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {  
                return slow;
            }
        }

        return nullptr; 
    }

  public:
    ListNode* detectCycle(ListNode* head) {
        if (!head) {
            return nullptr;  
        }

        ListNode* meetingPoint = find(head);  
        if (!meetingPoint) {
            return nullptr;  
        }

        ListNode* start = head;
        while (start != meetingPoint) {
            start = start->next;
            meetingPoint = meetingPoint->next;
        }

        return start; 
    }
};
