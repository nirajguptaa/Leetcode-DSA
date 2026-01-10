class Solution {
public:
    int minimumDeleteSum(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][0]+text1[i-1];
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=dp[0][j-1]+text2[j-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j]+text1[i-1],//del form text1
                    dp[i][j-1]+text2[j-1]);//del form text1
                }
            }
        }
        return dp[n][m];
    }
};