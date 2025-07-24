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
    // Finds and removes the first zero-sum subarray from temp
    bool removeFirstZeroSumRange(vector<int>& temp) {
        unordered_map<int, int> mp;
        int prefixSum = 0;
        mp[0] = -1; // handle prefix sum zero from start

        for(int i = 0; i < temp.size(); ++i) {
            prefixSum += temp[i];
            if(mp.find(prefixSum) != mp.end()) {
                int start = mp[prefixSum] + 1;
                int end = i;
                // Erase that range
                temp.erase(temp.begin() + start, temp.begin() + end + 1);
                return true; // found and removed
            }
            mp[prefixSum] = i;
        }
        return false; // no zero-sum subarray found
    }

public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> temp;

        // Convert linked list to array
        ListNode* cur = head;
        while(cur){
            temp.push_back(cur->val);
            cur = cur->next;
        }

        // Repeatedly remove first zero-sum subarray
        while(removeFirstZeroSumRange(temp));

        // Build new linked list from remaining elements
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for(int val : temp){
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy->next;
    }
};
