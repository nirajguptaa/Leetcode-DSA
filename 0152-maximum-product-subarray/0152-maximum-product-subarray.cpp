class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxx=nums[0],minn=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int prevMaxx=maxx;
            maxx=max({nums[i],nums[i]*maxx,nums[i]*minn});
            minn=min({nums[i],nums[i]*minn,nums[i]*prevMaxx});
            ans=max(maxx,ans);
        }
        return ans;
    }
};