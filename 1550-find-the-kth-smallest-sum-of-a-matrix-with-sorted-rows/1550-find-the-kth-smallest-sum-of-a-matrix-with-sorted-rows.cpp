class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> sums = mat[0];  

        for (int i = 1; i < mat.size(); i++) {
            priority_queue<int> pq;  
            for (int s : sums) {
                for (int x : mat[i]) {
                    pq.push(s + x);
                    if (pq.size() > k)
                        pq.pop();  
                }
            }

             vector<int> newSums;
            while (!pq.empty()) {
                newSums.push_back(pq.top());
                pq.pop();
            }
            reverse(newSums.begin(), newSums.end()); 
            sums = newSums;  
        }

        return sums[k-1];  // kth smallest
    }
};
