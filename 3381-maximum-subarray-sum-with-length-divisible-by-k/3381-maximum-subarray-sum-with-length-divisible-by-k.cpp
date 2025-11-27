class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long >prefix(k,LLONG_MAX);
        prefix[0]=0;
        long long res=LLONG_MIN;
        long long total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
            int len=i+1;
            int prefix_len=len%k;
            if(prefix[prefix_len]!=LLONG_MAX){
                res=max(total-prefix[prefix_len],res);
            }

            prefix[prefix_len]=min(prefix[prefix_len],total);
        }
        return res;
    }
};