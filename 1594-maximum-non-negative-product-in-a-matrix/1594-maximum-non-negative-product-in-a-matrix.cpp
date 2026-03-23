class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int MOD=1e9+7;
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<pair<long long,long long>>>dp(r,vector<pair<long long,long long>>(c,{INT_MAX,INT_MIN}));
        dp[0][0]={grid[0][0],grid[0][0]};
        
        for(int j=1;j<c;j++){
            int val=grid[0][j];
            dp[0][j].first=min(val*dp[0][j-1].first,val*dp[0][j-1].second);
            dp[0][j].second=max(val*dp[0][j-1].first,val*dp[0][j-1].second);
        }
        for(int i=1;i<r;i++){
            int val=grid[i][0];
            dp[i][0].first=min(val*dp[i-1][0].first,val*dp[i-1][0].second);
            dp[i][0].second=max(val*dp[i-1][0].first,val*dp[i-1][0].second);
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                int val=grid[i][j];
                long long a=val*dp[i-1][j].first;
                long long b=val*dp[i-1][j].second ;
                long long c1=val*dp[i][j-1].first ;
                long long d=val*dp[i][j-1].second;
                dp[i][j].first=min({a,b,c1,d});
                dp[i][j].second=max({a,b,c1,d});
            }
        }
        if(dp[r-1][c-1].second<0)return -1;
        return dp[r-1][c-1].second%MOD;

    }
};