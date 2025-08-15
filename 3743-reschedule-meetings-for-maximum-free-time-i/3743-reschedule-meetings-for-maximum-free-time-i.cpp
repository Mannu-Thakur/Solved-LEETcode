class Solution {
public:
    int maxFreeTime(int last, int k, vector<int>& s, vector<int>& e) {
        int n = s.size();

        vector<int>temp;
        // sub 2nd start and 1st end
      
          temp.push_back(s[0]);

        for(int i=1; i<n; ++i){
            temp.push_back(s[i] - e[i-1]);   
        }
         
        temp.push_back(last - e[e.size()-1]);

        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;
        while(j < temp.size()){
            sum += temp[j];

            if(i < temp.size() && j - i + 1 > k+1){
                sum -= temp[i];
                i++;
            }

            ans = max(ans, sum);
            j++;

        }

        return ans;
        

    }
};