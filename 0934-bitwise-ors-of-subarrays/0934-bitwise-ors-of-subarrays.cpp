class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;

        for (int i = 0; i < arr.size(); ++i) {
            unordered_set<int> curr;
            curr.insert(arr[i]);

            for (int val : prev) {
                curr.insert(val | arr[i]);
            }

            for (int val : curr) {
                result.insert(val);
            }

            prev = curr;
        }

        return result.size();
    }
};
