class Solution {
  bool solve(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}


   void suffix(vector<int>& temp, int num) {
    long long x = 10;
    while (x <= num) {
        temp.push_back(num % x);
        x *= 10;
    }
    temp.push_back(num);  
}

void prefix(vector<int>& temp1, int num) {
    string s = to_string(num);
    int value = 0;

    for (char c : s) {
        value = value * 10 + (c - '0'); 
        temp1.push_back(value);
    }
}


public:
    bool completePrime(int num) {
        
        string x = to_string(num);
        if(x.size() == 1) return solve(num);

        vector<int>temp, temp1;
        suffix(temp, num);
        prefix(temp1, num);

        for(int i=0; i<temp.size(); ++i){
            if(!(solve(temp[i]) && solve(temp1[i]))){
                return false;
            }
        }

return true;

    }
};