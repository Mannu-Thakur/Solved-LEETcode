class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int totalApples = 0;
        for (int x : apple) totalApples += x;

        sort(capacity.rbegin(), capacity.rend());

        int cur = 0;
        for (int i = 0; i < capacity.size(); i++) {
            cur += capacity[i];
            if (cur >= totalApples)
                return i + 1;    
        }

        return capacity.size();
    }
};
