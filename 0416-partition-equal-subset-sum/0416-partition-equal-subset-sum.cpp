class Solution {
public:
    bool f(int idx,int curr,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(curr==target){
            return true;
        }
        if(curr>target || idx>=nums.size()){
            return false;
        }
        if(dp[idx][curr]!=-1){
            return dp[idx][curr];
        }
        return dp[idx][curr]=f(idx+1,curr,target,nums,dp)||
        f(idx+1,curr+nums[idx],target,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        int half=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(half+1,-1));
        return f(0,0,half,nums,dp);

    }
};