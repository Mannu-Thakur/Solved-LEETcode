class Solution {
public:
    long long countVowels(string word) {
        long long cnt = 0;
        int n = word.size();

        for(int i=0; i<n; ++i){
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o'|| word[i] == 'u'){
                cnt += (long long)(n-i)*(i+1);
            }
        }

        return cnt;
    }
};