class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int>st;
        st.push(-1);

        unordered_map<char, char>mpp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        int len = 0;
        for(int i = 0; i<n; ++i){
            char c = s[i];

               if(c == '(' || c == '{' || c == '['){
                st.push(i);
               }else{
                if(!st.empty()){
                    st.pop();
                }

                if(!st.empty()){
                    len = max(len, i-st.top());
                }

                else{
                    st.push(i);
                }
               }
               
        }

        return len;
    }
};