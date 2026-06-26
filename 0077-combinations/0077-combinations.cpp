class Solution {
public:
    void f(int idx,int n,int k,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(idx>n)return ;
        
        temp.push_back(idx);
        f(idx+1,n,k,temp,ans);
        temp.pop_back();
        f(idx+1,n,k,temp,ans);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(1,n,k,temp,ans);
               
        return ans;
    }
};