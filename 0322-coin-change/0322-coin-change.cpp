class Solution {
public:
    int f(vector<int>& coins,int amount,vector<vector<int>>&dp,int ind){
        if(ind==0){
            if(amount%coins[0]==0)return amount/coins[0];
            return 1e8;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int nottake=f(coins,amount,dp,ind-1);

        int take=INT_MAX;
        if(amount>=coins[ind]){
            take=1+f(coins,amount-coins[ind],dp,ind);
        }
        return dp[ind][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(coins,amount,dp,n-1);
        if(ans>=1e8){
            return -1;
        }
        return ans;
    }
};