class Solution {
public:
    int solve(int k, int n, vector<vector<int>>& dp) {
        if (n == 1 || n == 0) {
            return n;
        }
        if (k == 1) {
            return n;
        }
        if (dp[k][n] != -1)
            return dp[k][n];
        int mini = INT_MAX;

        // for (int i = 1; i <= n; i++) {
        //     int temp=1+max(solve(k-1,i-1,dp),solve(k,n-i,dp));
        //     mini=min(mini,temp);
        // }

        int l=1,h=n;
        while(l<=h){
            int m=l+(h-l)/2;
            int breakEgg=solve(k-1,m-1,dp);
            int notBreak=solve(k,n-m,dp);
            int temp=1+max(breakEgg,notBreak);
            mini=min(mini,temp);
            if(breakEgg>notBreak){
                h=m-1;

            }else{
                l=m+1;
            }
        }
        return dp[k][n]=mini;
    };
    int superEggDrop(int k,int n){
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};