class Solution {
public:
    bool f(string &s,vector<string>& wordDict,vector<int>&dp,int idx){
        if(idx==s.size())return true;
        if(dp[idx]!=-1)return dp[idx];
        for(string word:wordDict){
            int len=word.size();
            if(idx+len<=s.size() && s.substr(idx,len)==word ){
                
                if(f(s,wordDict,dp,idx+len)){
                    return dp[idx]=1;
                }
            }

        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int len=s.size();
        vector<int>dp(len,-1);
        return f(s,wordDict,dp,0);
    }
};