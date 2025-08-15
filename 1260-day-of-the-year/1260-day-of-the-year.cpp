class Solution {
public:
    int dayOfYear(string date) {
        unordered_map<int, int> mp;
        // Correct month-day mapping
        mp[1] = 31;
        mp[2] = 28;
        mp[3] = 31;
        mp[4] = 30;
        mp[5] = 31;
        mp[6] = 30;
        mp[7] = 31;
        mp[8] = 31;
        mp[9] = 30;
        mp[10] = 31;
        mp[11] = 30;
        mp[12] = 31;

        int ans = 0;

        string month = to_string(stoi(date.substr(5, 2)));
        int temp = stoi(month);
        string datee = to_string(stoi(date.substr(8, 2)));
        int tem = stoi(datee);

        // Sum days of all previous months
        for (int i = 1; i < temp; ++i) {
            ans += mp[i];
        }
        ans += tem;

        // Leap year check
        int year = stoi(date.substr(0, 4));
        if (temp > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            ans += 1;
        }

        return ans;
    }
};
