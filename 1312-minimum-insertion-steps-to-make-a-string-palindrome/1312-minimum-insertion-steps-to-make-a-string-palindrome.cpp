class Solution {
public:
    int findLCS(string s,string r){
        int len=s.size();
        vector<vector<int>>dp(len+1,vector<int>(len+1,0));
        
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(s[i-1]==r[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[len][len];
    }
    int minInsertions(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int len=s.size();
        return len-findLCS(s,r);
    }
};