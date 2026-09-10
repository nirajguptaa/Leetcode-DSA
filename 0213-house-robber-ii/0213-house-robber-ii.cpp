class Solution {
public:
    int f(int s,int e,vector<int>&nums){
        int n=e-s+1;
        vector<int>dp(n+1,0);
        if(n==1){
            return nums[s];
        }
        if(n==2){
            return max(nums[s],nums[s+1]);
        }
        dp[1]=nums[s];
        dp[2]=max(nums[s],nums[s+1]);
        for(int i=3;i<=n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[s+i-1]);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];

        return max(f(0,n-2,nums),f(1,n-1,nums));
    }
};