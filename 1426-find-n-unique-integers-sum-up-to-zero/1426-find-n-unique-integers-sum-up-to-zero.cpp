class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>temp;
        if(n == 1) return {0};
        int cnt = n;

        int steps = 0;

         int i=1;
        if(n % 2){
            cnt  = cnt - 1;
            temp.push_back(0);
            
            while(cnt--){
                temp.push_back(i);
                i = -i;
                steps++;
                if(steps % 2 == 0){
                    i++;
                }
            }
             
        }else{

            while(cnt--){
                temp.push_back(i);
                i = -i;
                steps++;
                if(steps % 2 == 0){
                    i++;
                }
            }

        }
        return temp;
    }
};