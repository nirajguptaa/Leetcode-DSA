class Solution {
public:
    void dfs(int pos,int n,int k,int cost,string &curr,vector<string>&ans){
        if(cost>k){
            return ;
        }
        if(pos==n){
            ans.push_back(curr);
            return ;
        }
        curr.push_back('0');
        dfs(pos+1,n,k,cost,curr,ans);
        curr.pop_back();
        if(pos==0 || curr.back()!='1'){
            curr.push_back('1');
            dfs(pos+1,n,k,cost+pos,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        string curr;
        dfs(0,n,k,0,curr,ans);
        return ans;
    }
};