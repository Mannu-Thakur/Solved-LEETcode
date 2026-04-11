class Solution {
public:
    string trafficSignal(int timer) {
        string ans = "Invalid";

        if( timer == 0){
            ans = "Green";
        }

        if( timer == 30){
            ans = "Orange";
        }

        if(timer > 30 && timer <= 90){
            ans = "Red";
        }

        return ans;
    }
};