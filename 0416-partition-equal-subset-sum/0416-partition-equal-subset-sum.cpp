class Solution {
public:
    bool f(int i,int curr,int half,vector<int>&nums,vector<vector<int>>&dp){

        if(curr==half){
            return true;
        }
        if(curr>half || i>=nums.size()){
            return false;
        }
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }

        return dp[i][curr]=f(i+1,curr+nums[i],half,nums,dp)||f(i+1,curr,half,nums,dp);

    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2!=0){
            return false;
        }
        int half=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(half+1,-1));
        return f(0,0,half,nums,dp);
    }
};