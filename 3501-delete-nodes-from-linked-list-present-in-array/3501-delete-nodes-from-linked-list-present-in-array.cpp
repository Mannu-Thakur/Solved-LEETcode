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
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> removeSet(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (head) {
            if (removeSet.find(head->val) == removeSet.end()) {
                curr->next = new ListNode(head->val);
                curr = curr->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};
