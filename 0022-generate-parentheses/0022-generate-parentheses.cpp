class Solution {
public:
    void f(string curr,int open,int close,int n,vector<string>&ans){
        if(open==n && close==n){
            ans.push_back(curr);
            return ;
        }
        if(open>n || close>n || close>open){
            return ;
        }
        f(curr+"(",open+1,close,n,ans);
        f(curr+")",open,close+1,n,ans);
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        f("",0,0,n,ans);
        return ans;
    }
};