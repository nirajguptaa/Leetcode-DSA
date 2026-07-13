class Solution {
public:
    void f(int start,int currSum,int k,int n,vector<int>&curr,vector<vector<int>>&ans){
        if(curr.size()==k){
            if(currSum==n){
                ans.push_back(curr);
            }
            return;
        }
        if(currSum>=n)return;
       
        for(int i=start;i<=9;i++){
            curr.push_back(i);
            f(i+1,currSum+i,k,n,curr,ans);
            curr.pop_back();
                     
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>curr;
        f(1,0,k,n,curr,ans);
        return ans;
    }
};