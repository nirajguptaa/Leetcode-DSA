class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        int ans=nums[0];
        int minn=nums[0],maxx=nums[0];
        for(int i=1;i<n;i++){
            int prevMax=maxx;
            maxx=max({nums[i],maxx*nums[i],minn*nums[i]});
            minn=min({nums[i],prevMax*nums[i],minn*nums[i]});
           
            ans=max(maxx,ans);
        }
        return ans;
    }
};