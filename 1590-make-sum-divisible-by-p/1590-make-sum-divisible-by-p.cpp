class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long  sum=accumulate(nums.begin(),nums.end(),0LL);
        
        int tar=sum%p;
        if(tar==0)return 0;
        unordered_map<int ,int>mp;
        int curr=0;
        mp[0]=-1;
        int n=nums.size();
        int res=n;
        for(int i=0;i<n;i++){
            curr=(curr+nums[i])%p;
            int remain=(curr-tar+p)%p;
            if(mp.find(remain)!=mp.end()){
                res=min(res,i-mp[remain]);
            }
            mp[curr]=i;
        }
        return res==n?-1:res;
    }
};