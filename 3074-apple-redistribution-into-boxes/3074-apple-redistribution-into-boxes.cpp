class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();

        sort(capacity.rbegin(), capacity.rend());
        int sum = 0;
        for(auto &f: apple){
            sum += f;
        }


        int cnt  = 0, cur = 0;
        int ans=0;
        for(auto &f: capacity){
            cur += f;
            cnt++;

            if(cur >= sum){
                ans = cnt;
                break;
            }
        }
        return cnt;
    }
};