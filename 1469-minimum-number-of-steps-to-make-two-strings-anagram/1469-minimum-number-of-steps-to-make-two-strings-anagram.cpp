class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);
        
        for (char c : s) freq[c - 'a']++;
        for (char c : t) {
            if (freq[c - 'a'] > 0) freq[c - 'a']--;
        }
        
        int steps = 0;
        for (int count : freq) steps += count;
        return steps;
    }
};
