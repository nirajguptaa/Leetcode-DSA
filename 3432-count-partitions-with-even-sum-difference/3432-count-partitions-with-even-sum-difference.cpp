class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int right=accumulate(nums.begin(),nums.end(),0);
        int left=0;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            right-=nums[i];
            if(abs(right-left)%2==0){
                count++;
            }
        }
        return count;
        
    }
};