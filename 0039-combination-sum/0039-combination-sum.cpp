class Solution {
public:
    void f(int currSum,int idx,vector<int>&curr,vector<vector<int>>&ans,vector<int>& candidates, int target){
        if(currSum==target){
            ans.push_back(curr);
            return ;
        }
        int n=candidates.size();
        if(currSum >target || idx==n){
            return ;
        }
        
        curr.push_back(candidates[idx]);
        f(currSum+candidates[idx],idx,curr,ans,candidates,target);
        curr.pop_back();
        
        f(currSum,idx+1,curr,ans,candidates,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        f(0,0,curr,ans,candidates,target);
        return ans;
    }
};