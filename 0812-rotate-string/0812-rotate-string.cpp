class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if( n!= m) return false;

        string newS = s + s;
        return (newS.find(goal) != std::string::npos);
    }
};