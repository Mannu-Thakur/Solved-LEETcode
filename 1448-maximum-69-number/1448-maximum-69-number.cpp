class Solution {
public:
    int maximum69Number (int num) {
        string temp = to_string(num);

        for(int i=0; i<temp.size(); ++i){
            if(temp[i] == '9')  continue;
            else{
                temp[i] = '9';
                break;
            }
        }
        return stoi(temp);
            }
};