class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int pivot=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }

        }
        if(pivot==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        int max=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[pivot]){
                max=i;
                break;
            }
        }
        swap(nums[pivot],nums[max]);
        reverse(nums.begin()+pivot+1,nums.end());
    }
};