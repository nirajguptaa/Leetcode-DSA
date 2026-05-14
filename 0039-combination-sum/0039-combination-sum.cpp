class Solution {
public:
    void f(int sum,int idx,vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&curr){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        int n=candidates.size();
        if(sum>target || idx>n){
            return ;
        }
        if(idx<n){

            curr.push_back(candidates[idx]);
            f(sum+candidates[idx],idx,candidates,target,ans,curr);
            curr.pop_back();
        }
        f(sum,idx+1,candidates,target,ans,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        f(0,0,candidates,target,ans,curr);
        return ans;
    }
};