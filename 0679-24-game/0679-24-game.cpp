class Solution {
    double eps = 0.1;


    bool solve(vector<double>&cards){
        int n = cards.size();

       if(cards.size() == 1){
        return abs(cards[0] - 24) <= eps;
       }


        for(int i=0; i<n; ++i){
            for(int j = 0; j<n; ++j){

                if(i == j) continue;

                double a = cards[i];
                double b = cards[j];

                vector<double>temp; // to store rest elements
                for(int k=0; k<n; k++){
                    if(k != i && k != j)
                    temp.push_back(cards[k]);
                }

                vector<double>possible_vals = {a-b, b-a, a*b, a+b};
                if(abs(b) > 0.0){
                    possible_vals.push_back(a/b);
                }

                if(abs(a) > 0.0 ){
                    possible_vals.push_back(b/a);
                }
                for(auto &f: possible_vals){
                    temp.push_back(f);
                    if(solve(temp) == true){
                        return true;
                    }else{
                        temp.pop_back();
                    }
                }
                 
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        int n = cards.size();

        vector<double>nums;
        for(int i=0; i<n; ++i){
            nums.push_back(cards[i] * 1.0);
        }

        return solve(nums);

    }
};