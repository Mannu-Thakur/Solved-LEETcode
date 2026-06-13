class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n % 2 != 0) {
            return false;
        }

        stack<char> st;
        unordered_map<char, char> brackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (auto &c : s) {
            if (brackets.count(c)) { 
                if (st.empty() || st.top() != brackets[c]) {
                    return false;
                }
                st.pop(); 
            } else { 
                st.push(c);
            }
        }

        return st.empty();
    }
};
