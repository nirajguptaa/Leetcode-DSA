class Solution {
public:
    int f(int prev,int curr,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(curr==n)return 0;
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }
        int notake=f(prev,curr+1,nums,dp);
        int take=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            take=1+f(curr,curr+1,nums,dp);
        }
        return dp[prev+1][curr]=max(notake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return f(-1,0,nums,dp);
        


    }
};