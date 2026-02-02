class Solution {
public:
    bool f(int ind,string &s, vector<string>& wordDict,vector<int>&dp){
        if(ind==s.size())return true;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(auto word:wordDict){
            int len=word.size();
            if(ind+len<=s.size() && s.substr(ind,len)==word){
                if(f(ind+len,s,wordDict,dp)){
                    return dp[ind]=true;
                }
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int m=s.size();
        int n=wordDict.size();
        vector<int>dp(m,-1);
        return f(0,s,wordDict,dp);
    }
};