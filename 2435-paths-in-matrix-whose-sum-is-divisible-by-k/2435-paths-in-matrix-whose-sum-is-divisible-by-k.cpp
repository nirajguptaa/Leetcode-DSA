class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int mod=1e9+7;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,0)));
        // number of paths reaching cell (i, j) with sum%k=r
        dp[0][0][grid[0][0]%k]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int r=0;r<k;r++){
                    if(dp[i][j][r]==0)continue;
                    if(i+1<m){
                        int newR=(r+grid[i+1][j])%k;
                        dp[i+1][j][newR]=(dp[i][j][r]+dp[i+1][j][newR])%mod;
                    }
                    if(j+1<n){
                        int newR=(r+grid[i][j+1])%k;
                        dp[i][j+1][newR]=(dp[i][j][r]+dp[i][j+1][newR])%mod;
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
        
    }
};