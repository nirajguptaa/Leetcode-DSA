class Solution {
public:
    bool canForm(string s,int idx,unordered_set<string>&dict,vector<int>&dp){
        int n=s.size();
        if(idx>=n){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(int end=idx;end<=n;end++){
            string sub=s.substr(idx,end-idx+1);
            
            if(dict.count(sub)){
                int len=sub.size();
                if(canForm(s,idx+len,dict,dp)){
                    return dp[idx]=true;
                }
            }
        }
        return dp[idx]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        unordered_set<string>dict(words.begin(),words.end());
        for(string &curr:words){
            vector<int>dp(curr.size(),-1);
            dict.erase(curr);
            if(canForm(curr,0,dict,dp)){
                ans.push_back(curr);
            }
           dict.insert(curr);
            
        }
        return ans;
    }
};