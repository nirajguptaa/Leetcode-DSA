class Solution {
public:
    int f(int idx,int e,vector<int>&nums,vector<int>&dp){
        if(idx>e)return 0;
        if(dp[idx]!=-1){
            return dp[idx];
        }

        int rob=nums[idx]+f(idx+2,e,nums,dp);
        int skip=f(idx+1,e,nums,dp);

        return dp[idx]=max(rob,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        vector<int> dp1(n, -1);

        vector<int> dp2(n, -1);
        int c1= f(0,n-2,nums,dp1);
        int c2= f(1,n-1,nums,dp2);
        return max(c1,c2);
    }
};