class Solution {
public:
   int minDiff = INT_MAX;
   vector<int> best;

   void backtrack(int n, int k, vector<int> vect){
       if(k == 1){
           vect.push_back(n);
           checkMaxDiff(vect);
           return;
       }

       for(int i = 1; i<=sqrt(n)+1; i++){
           if(n%i == 0){
               vect.push_back(i);
               backtrack(n/i, k-1, vect);
               vect.pop_back();
           }
       }
   }

   
   void checkMaxDiff(vector<int> v){
       int mx = *max_element(v.begin(), v.end());
       int mn = *min_element(v.begin(), v.end());
       if(minDiff > mx-mn){
           minDiff = mx-mn;
           best = v;
       }
   }

   
   vector<int> minDifference(int n, int k) {
       vector<int> vect;
       backtrack(n, k, vect);
       return best; 
       
   }
};