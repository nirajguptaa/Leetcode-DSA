class Solution {
public:
    void f(int idx,vector<int>& nums,vector<int>&curr,vector<vector<int>>&ans){
        int n=nums.size();
        if(idx==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        f(idx+1,nums,curr,ans);
        curr.pop_back();
        while(idx+1<n && nums[idx]==nums[idx+1]){
            idx++;
        }
        f(idx+1,nums,curr,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        f(0,nums,curr,ans);
        return ans;
    }
};