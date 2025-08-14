class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();

        unordered_map<char, int> mp;
        int i = 0, j = 0;

        while (j < n) {
            mp[num[j]]++;

             if (j - i + 1 > 3) {
                mp[num[i]]--;
                if (mp[num[i]] == 0) {
                    mp.erase(num[i]);
                }
                i++;
            }

             if (j - i + 1 == 3 && mp.size() == 1) {
                string temp = num.substr(i, 3);
                if (temp > ans) {
                    ans = temp;
                }
            }

            j++;
        }
        return ans;
    }
};
