class Solution {
public:
    void f(int sum,int idx, vector<int>&curr,vector<vector<int>>&ans,vector<int>& candidates, int target){
        
        if(sum==target){
            ans.push_back(curr);
            return ;
        }
        if(idx>=candidates.size() || sum>target){
            return ;
        }
        if(candidates[idx]<=target){
            curr.push_back(candidates[idx]);
            f(sum+candidates[idx],idx,curr,ans,candidates,target);
            curr.pop_back();
        }
        f(sum,idx+1,curr,ans,candidates,target);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        f(0,0,curr,ans,candidates,target);
        return ans;

    }
};