// class Solution {
// public:
//     int reverseNum(int x) {
//         int temp = 0;
//         while (x > 0) {
//             temp = temp * 10 + (x % 10);
//             x /= 10;
//         }
//         return temp;
//     }

//     int minMirrorPairDistance(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         int res = INT_MAX;

//         for (int i = 0; i < nums.size(); ++i) {
//             int rev = reverseNum(nums[i]);

//             if (mp.find(rev) != mp.end()) {
//                 res = min(res, i - mp[rev]);
//             }

//             mp[nums[i]] = i;
//         }

//         return res == INT_MAX ? -1 : res;
//     }
// };

class Solution {
public:
    int reverseNum(int x) {
        int temp = 0;
        while (x > 0) {
            temp = temp * 10 + (x % 10);
            x /= 10;
        }
        return temp;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            int rev = reverseNum(nums[i]);

            if (mp.find(nums[i]) != mp.end()) {
                res = min(res, i - mp[nums[i]]);
            }

            mp[rev] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};