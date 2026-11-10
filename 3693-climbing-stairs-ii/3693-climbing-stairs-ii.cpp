class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 3; k++) {
                int prev = j - k;
                if(prev>=0 && dp[prev]!=1e9){
                    dp[j] = min(dp[j], dp[prev]+costs[j-1]+ k*k);
                }
            }
        }
        return dp[n];
    }
    
};