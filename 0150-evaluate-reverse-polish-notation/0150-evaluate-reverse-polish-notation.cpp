class Solution {
     int solve(int a, int b, char op){
            if(op == '+') return a+b;
            else if(op == '*') return a*b;
            else if(op == '-') return a-b;
            else return a/b;
        }

public:
    int evalRPN(vector<string>&nums) {
        int n = nums.size();
        stack<int>st;
        for(int i=0; i<n; ++i){
            if(nums[i].size() == 1 && !isdigit(nums[i][0])){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(solve(b, a, nums[i][0]));
            }
            else{
                st.push(stoi(nums[i]));
            }

        }
            return st.top();
    }
};