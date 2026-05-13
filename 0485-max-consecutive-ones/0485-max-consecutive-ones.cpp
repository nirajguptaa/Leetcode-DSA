class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len=0;
        int n=nums.size();
        int l=0,r=0;
        while(r<n){
            if(nums[r]==1){
                r++;
                len=max(len,r-l);
            }else{
                l=r+1;
                r=l;
            }
        }
        return len;
        
    }
};