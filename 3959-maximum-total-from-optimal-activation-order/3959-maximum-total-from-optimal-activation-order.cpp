 

class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < value.size(); i++) {
            mp[limit[i]].push_back(value[i]);
        }

        long long ans = 0;

        for (auto& [currLimit, elements] : mp) {
            sort(elements.begin(), elements.end(), greater<int>());
            for (int i = 0; i < min(currLimit, (int)elements.size()); i++) {
                ans += elements[i];
            }
        }

        return ans;
    }
};
