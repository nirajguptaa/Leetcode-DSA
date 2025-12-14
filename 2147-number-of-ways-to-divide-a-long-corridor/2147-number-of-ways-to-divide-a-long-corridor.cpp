class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9 + 7;
        long long ways = 1;
        int seat = 0;
        int plant = 0;
        bool firstTime = false;
        for (char ch : corridor) {
            if (ch == 'S') {
                seat++;
                if (seat == 2) {
                    if (firstTime) {
                        ways = (ways * (plant + 1)) % mod;
                    }
                    firstTime = true;
                    seat = 0;
                    plant = 0;
                }
            }else{
                if(firstTime && seat==0){
                    plant++;
                }
            }
        }
        if(!firstTime || seat!=0){
            return 0;
        }
        return ways;
            
    }
};