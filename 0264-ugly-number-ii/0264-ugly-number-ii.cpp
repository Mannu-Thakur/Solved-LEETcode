class Solution {
public:
    int nthUglyNumber(int n) {
         priority_queue<long, vector<long>, greater<long>> minHeap;
      
         unordered_set<long> visited{{1L}};
      
         minHeap.push(1L);
      
         long currentUglyNumber = 1;
      
         vector<int> primeFactors = {2, 3, 5};
      
         while (n--) {
             currentUglyNumber = minHeap.top();
            minHeap.pop();
          
             for (int& prime : primeFactors) {
                long nextUglyNumber = currentUglyNumber * prime;
              
                 if (!visited.count(nextUglyNumber)) {
                    visited.insert(nextUglyNumber);
                    minHeap.push(nextUglyNumber);
                }
            }
        }
      
         return static_cast<int>(currentUglyNumber);
    }
};
