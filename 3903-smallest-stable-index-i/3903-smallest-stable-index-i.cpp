class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxi(n,0);
        vector<int>mini(n,1e8);
        int currMax=nums[0];
        int currMin=nums[n-1];
        for(int i=0;i<n;i++){
            currMax=max(currMax,nums[i]);
            maxi[i]=max(currMax,nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            currMin=min(currMin,nums[i]);
            mini[i]=min(currMin,nums[i]);
        }
        for(int i=0;i<n;i++){
            if(maxi[i]-mini[i]<=k){
                return i;
            }
        }
        return -1;
    }
};