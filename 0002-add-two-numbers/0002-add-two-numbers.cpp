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
   vector<int> linkedListToVector(ListNode* head) {
    vector<int> result;
    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

ListNode* vectorToLinkedList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> num1 = linkedListToVector(l1);
    vector<int> num2 = linkedListToVector(l2);

    vector<int> result;
    int carry = 0, i = 0;

    while (i < num1.size() || i < num2.size() || carry > 0) {
        int digit1 = (i < num1.size()) ? num1[i] : 0;
        int digit2 = (i < num2.size()) ? num2[i] : 0;
        int sum = digit1 + digit2 + carry;
        result.push_back(sum % 10);  
        carry = sum / 10;           
        ++i;
    }

    return vectorToLinkedList(result);
}
};