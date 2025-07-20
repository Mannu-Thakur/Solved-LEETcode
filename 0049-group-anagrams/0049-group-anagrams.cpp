class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            groups[sortedStr].push_back(str);
        }
        
        vector<vector<string>> result;
        for (const auto& group : groups) {
            result.push_back(group.second);
        }
        
        return result;
    }
};
