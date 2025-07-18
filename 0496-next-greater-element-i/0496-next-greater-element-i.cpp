class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> nextGreater; // maps nums2[i] → next greater element
        stack<int> st;
        
        // Traverse nums2 and compute next greater element for each
        for(int i = 0; i < m; ++i) {
            while(!st.empty() && nums2[i] > st.top()) {
                nextGreater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        // Build result for nums1 by looking up in map
        vector<int> res;
        for(int num : nums1) {
            res.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
        }
        
        return res;
    }
};
