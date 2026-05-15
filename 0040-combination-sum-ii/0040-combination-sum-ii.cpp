class Solution {
public:
    void f(int sum,int idx,vector<int>& candidates, int target,vector<int>&temp,vector<vector<int>>&ans){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        int n=candidates.size();
        if(sum>target || idx>n-1){
            return;
        }

        temp.push_back(candidates[idx]);
        f(sum+candidates[idx],idx+1,candidates,target,temp,ans);
        temp.pop_back();
        while(idx+1<n && candidates[idx]==candidates[idx+1]){
            idx++;
        }
        f(sum,idx+1,candidates,target,temp,ans);
            
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,0,candidates,target,temp,ans);
        return ans;
    }
};