class Solution {
public:
    int sum(int n){
        int val=0;
        while(n>0){
            val+=n%10;
            n/=10;
        }
        return val;
    }
    int smallestIndex(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sumDigit=sum(nums[i]);
            if(i==sumDigit){

                ans=min(ans,sumDigit);
            }

        }
        return ans==INT_MAX?-1:ans;
        
    }
};