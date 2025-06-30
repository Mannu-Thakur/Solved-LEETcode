// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         int cnt = INT_MIN;

//         unordered_map<int, int>mpp;
//         for(auto &f : edges){
//             int a = f[0];
//             int b = f[1];
//             mpp[a]++;
//             mpp[b]++;
//         }
//         int num = 0;

//         for(auto &x: mpp){
//             if(cnt < x.second){
//                 cnt = x.second;
//                 num = x.first;
//             }
//         }

//         return num;
//     }
// };/

class Solution {
public:
int findCenter(vector<vector<int>>& e) {
    return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
}
};