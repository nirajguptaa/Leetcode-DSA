class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefSum(n+1);
        for(int i=0;i<n;i++){
            prefSum[i+1]=prefSum[i]+nums[i];
        }
        double ans=-1e9;
        for(int i=k-1;i<n;i++){
            int curr=prefSum[i+1]-prefSum[i-k+1];
            double temp=(double)curr/k;
            ans=max(temp,ans);
        }
        return ans;
    }
};