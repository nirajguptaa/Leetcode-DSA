class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int>freq(51);
        for(int num:nums){
            freq[num]++;
        }
        int n=nums.size();
        if(n==k){
            return *max_element(nums.begin(),nums.end());
        }
        if(k==1){
            int ans=-1;
            for(int x:nums){
                if(freq[x]==1){
                    ans=max(x,ans);
                }
            }
            return ans;
        }
        int first=nums[0];
        int last=nums[n-1];
        int first_freq=0,last_freq=0;
        for(int num:nums){
            if(num==first){
                first_freq+=1;
            }
            if(num==last){
                last_freq+=1;
            }
        }
        int ans=-1;

        if(first_freq==1){
            ans=max(ans,first);
        }
        if(last_freq==1){
            ans=max(ans,last);
        }
        return ans;
    }
};