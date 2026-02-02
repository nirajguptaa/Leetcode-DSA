class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1e8);
        dp[0]=0;
        for(int c:coins){
            for(int i=c;i<=amount;i++){
                dp[i]=min(dp[i],1+dp[i-c]);
            }
        }
        return dp[amount]>=1e8?-1:dp[amount];
    }
};