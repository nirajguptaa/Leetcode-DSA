class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1=0;
        int l=0,r=0;
        while(r<nums.size()){
            if(nums[r]==1){
                r++;
                max1=max(r-l,max1);
            }else{

            l=r+1;
            r=l;
            }
        }
        return max1;
    }
};