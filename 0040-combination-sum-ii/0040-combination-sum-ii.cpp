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
        f(currSum+candidates[idx],idx+1,curr,ans,candidates,target);
        curr.pop_back();
        while(idx+1<n && candidates[idx]==candidates[idx+1]){
            idx++;
        }
        
        f(currSum,idx+1,curr,ans,candidates,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        f(0,0,curr,ans,candidates,target);
        return ans;
    }
};