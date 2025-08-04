class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n == 0) return 0; 
        if (n == 1) return 1; 

        int l = 0; 
        int i = 0; 
        int j = 0; 
        unordered_map<int, int> mpp; 

        while (j < n) {
            mpp[fruits[j]]++; 

            while (mpp.size() > 2) {
                mpp[fruits[i]]--; 
                if (mpp[fruits[i]] == 0) {
                    mpp.erase(fruits[i]); 
                }
                i++; 
            }

            l = max(l, j - i + 1);
            j++; 
        }

        return l; 
    }
};
