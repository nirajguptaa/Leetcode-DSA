class Solution {
public:
    int f(int idx,int curr,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(idx==nums.size()){
            return curr==target;
        }
        if(dp[idx][curr+1000]!=-1){
            return dp[idx][curr+1000];
        }
        int plus=f(idx+1,curr+nums[idx],nums,target,dp);
        int minus=f(idx+1,curr-nums[idx],nums,target,dp);
        return dp[idx][curr+1000]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2000+1,-1));
        return f(0,0,nums,target,dp);
        
    }
};