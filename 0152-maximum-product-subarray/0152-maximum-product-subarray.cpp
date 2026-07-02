class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
        int minn=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int prevMax=maxi;
            maxi=max({nums[i],minn*nums[i],nums[i]*maxi});
            minn=min({nums[i],minn*nums[i],nums[i]*prevMax});
            ans=max(maxi,ans);
        }
        return ans;
    }
};