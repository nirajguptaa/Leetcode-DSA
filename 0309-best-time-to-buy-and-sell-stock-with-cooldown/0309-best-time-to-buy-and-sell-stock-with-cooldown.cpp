class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n+2,0);
        for(int buy=n-1;buy>=0;buy--){
            for(int sell=buy+1;sell<n;sell++){
                dp[buy]=max(dp[buy],dp[sell+2]+(prices[sell]-prices[buy]));
            }
        }
        return dp[0];
    }
};