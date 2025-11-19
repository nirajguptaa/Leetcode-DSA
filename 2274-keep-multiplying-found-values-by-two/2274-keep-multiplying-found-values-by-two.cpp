class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int ans=original;
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==ans){
                ans=ans*2;
            }
            i++;
        }
        return ans;
    }
};