class Solution {
public:
    int canform(int idx,string s,vector<string>&wordDict,vector<int>&dp){
        int n=s.size();
        if(idx==n)return true;
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(auto w:wordDict){
            int len=w.size();
            if(idx+len<=n && s.substr(idx,len)==w){
                if(canform(idx+len,s,wordDict,dp)){
                    return dp[idx]=true;
                }
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        return canform(0,s,wordDict,dp);

    }
};