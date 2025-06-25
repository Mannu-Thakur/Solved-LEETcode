 

class Solution {
  public:
  vector<int> relativeSortArray(vector<int>& A1, vector<int>& A2){
        unordered_map<int, int> freq;
        int N = A1.size();
        int M = A2.size();
        vector<int> result;

        // Count frequency of each element in A1
        for (int i = 0; i < N; ++i) {
            freq[A1[i]]++;
        }

        // Append elements in order of A2
        for (int i = 0; i < M; ++i) {
            if (freq.find(A2[i]) != freq.end()) {
                while (freq[A2[i]]--) {
                    result.push_back(A2[i]);
                }
                freq.erase(A2[i]);
            }
        }

        // Collect remaining elements from A1 (not in A2)
        vector<int> remaining;
        for (auto &entry : freq) {
            while (entry.second--) {
                remaining.push_back(entry.first);
            }
        }

        // Sort remaining elements
        sort(remaining.begin(), remaining.end());

        // Append them to result
        result.insert(result.end(), remaining.begin(), remaining.end());

        return result;
    }
};