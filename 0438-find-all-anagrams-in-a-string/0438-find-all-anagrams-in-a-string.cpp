class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    unordered_map<char, int> p_count, s_count;

    for(char c : p) p_count[c]++;

    int window = p.size();

    for(int i = 0; i < s.size(); i++) {
        s_count[s[i]]++;

        // remove char that slides out of window
        if(i >= window) {
            if(s_count[s[i - window]] == 1)
                s_count.erase(s[i - window]);
            else
                s_count[s[i - window]]--;
        }

        if(s_count == p_count)
            ans.push_back(i - window + 1);
    }

    return ans;
}

};