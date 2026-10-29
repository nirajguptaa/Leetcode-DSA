class Solution {
public:
    int canForm(int idx,int n,string s,vector<int>&dp,vector<string>& wordDict){
        if(idx==n){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(string &str:wordDict){
            int len=str.size();
            if(idx+len<=n && str==s.substr(idx,len)){
                if(canForm(idx+len,n,s,dp,wordDict)){
                    return dp[idx]=true;
                }
            }
        }
        return dp[idx]=false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return canForm(0,n,s,dp,wordDict);
    }
};