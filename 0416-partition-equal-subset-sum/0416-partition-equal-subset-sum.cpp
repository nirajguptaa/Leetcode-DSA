class Solution {
public:
    bool f(vector<int>&nums,int sum,int ind,vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(ind==0){
            return sum==nums[0];
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int nottake=f(nums,sum,ind-1,dp);
        bool take=false;
        if(sum>=nums[ind]){
             take=f(nums,sum-nums[ind],ind-1,dp);
        }
        return dp[ind][sum]=take||nottake;
        
            
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return f(nums,sum/2,n-1,dp);
    }
};