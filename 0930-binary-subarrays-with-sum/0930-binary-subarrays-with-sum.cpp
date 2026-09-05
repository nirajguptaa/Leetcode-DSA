class Solution {
public:
    int exactSum(vector<int>& nums, int goal){
        if(goal<0)return 0;
        int l=0,n=nums.size();
        int curr=0;
        int count=0;
        int r=0;
        while(r<n ){
            curr+=nums[r];
            while(curr>goal){
                curr-=nums[l];
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return exactSum(nums,goal)-exactSum(nums,goal-1);
    }
};