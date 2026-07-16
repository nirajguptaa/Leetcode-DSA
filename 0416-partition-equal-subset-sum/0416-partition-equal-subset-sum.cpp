class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2!=0){
            return false;
        }
        int half=sum/2;
        // dp[x] is it possible to make sum x
       vector<bool>dp(half+1,false);
       dp[0]=true;
       for(int num:nums){
        for(int j=half;j>=num;j--){
            dp[j]=dp[j]||dp[j-num];
        }
       }
       return dp[half];
        

    
    }
};