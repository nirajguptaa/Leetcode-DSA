class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int curr=1,prev=0,ans=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curr+=1;
            }else{
                prev=curr;
                curr=1;
            }
            ans=max(ans,curr/2);
            ans=max(ans,min(prev,curr));
        }
        return ans;
    }
};