class Solution {
public:
    int f(int k,int n,vector<vector<int>>&dp){
        if(n==0 || n==1){
            return n;
        }
        if(k==1){
            return n;
        }
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        int mini=INT_MAX;
        int l=1,h=n;
        while(l<=h){
            int m=l+(h-l)/2;
            int breakEgg=f(k-1,m-1,dp);
            int notbreak=f(k,n-m,dp);
            int temp=1+max(breakEgg,notbreak);
            mini=min(mini,temp);
            if(breakEgg>notbreak){
                h=m-1;
            }else{
                l=m+1;
            }

        }
        return dp[k][n]=mini;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return f(k,n,dp);
    }
};