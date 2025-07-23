class Solution {
public:
    int maximumGain(string s, int x, int y) {
        return max(
            calculateScore(s, x, y, 'a', 'b'),  // x > y → remove "ab" first
            calculateScore(s, y, x, 'b', 'a')   // y > x → remove "ba" first
        );
    }

    int calculateScore(string s, int firstScore, int secondScore, char firstLeft, char firstRight) {
        stack<char> st;
        int score = 0;

        // First pass: remove higher scoring pair
        for (char ch : s) {
            if (!st.empty() && st.top() == firstLeft && ch == firstRight) {
                st.pop();
                score += firstScore;
            } else {
                st.push(ch);
            }
        }

        // Build remaining string
        string rem = "";
        while (!st.empty()) {
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());

        // Second pass: remove the other pair
        for (char ch : rem) {
            if (!st.empty() && st.top() == firstRight && ch == firstLeft) {
                st.pop();
                score += secondScore;
            } else {
                st.push(ch);
            }
        }

        return score;
    }
};
