class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<unordered_set<int>>>dp(m,vector<unordered_set<int>>(n));
        dp[0][0].insert(grid[0][0]);
        for(int i=1;i<m;i++){
            for (int x : dp[i - 1][0]) {
                dp[i][0].insert(grid[i][0] ^ x);
            }
        }
        for(int j=1;j<n;j++){
            for (int x : dp[0][j-1]) {
                dp[0][j].insert(grid[0][j] ^ x);
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                for(int x:dp[i-1][j]){
                    dp[i][j].insert(grid[i][j]^x);
                }
                for(int x:dp[i][j-1]){
                    dp[i][j].insert(grid[i][j]^x);
                }
                
            }
        }
        return *min_element(dp[m-1][n-1].begin(),dp[m-1][n-1].end());
    }
};