class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        if ((m + n - 1) % 2 != 0)
            return false;

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(m + n, 0)));
        dp[0][0][1]=true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int bal=0;bal<m+n;bal++){
                    if(!dp[i][j][bal]){
                        continue;
                    }
                    if(j+1<n){
                        int newBal=bal+(grid[i][j+1]=='('?1:-1);
                        if(newBal>=0){
                            dp[i][j+1][newBal]=true;
                        }
                    }
                    if(i+1<m){
                        int newBal=bal+(grid[i+1][j]=='('?1:-1);
                        if(newBal>=0){
                            dp[i+1][j][newBal]=true;
                        }
                    }
                }
            }
        }
       
        if(dp[m-1][n-1][0]==true){
            return true;
        }
        
        return false;

    }
};