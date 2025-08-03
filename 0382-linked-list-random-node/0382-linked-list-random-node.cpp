class Solution {
    vector<int> temp;
public:
    Solution(ListNode* head) {
        while(head){
            temp.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int idx = rand() % temp.size();
        return temp[idx];
    }
};
