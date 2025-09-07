#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                res[st.top()] = i;   
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> prevLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                res[st.top()] = i;  
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = prevLargerElement(nums);
        vector<int> b = nextLargerElement(nums);

        long long cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != -1 && a[i] < i - 1) cnt++;
            if (b[i] != -1 && nums[b[i]] != nums[i] && b[i] > i + 1) cnt++;
        }
        return cnt;
    }
};
