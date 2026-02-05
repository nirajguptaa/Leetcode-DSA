class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                res[i]=nums[i];
            }else if(nums[i]>0){
                res[i]=nums[(i+nums[i])%n];
            }else{
                int val=abs(nums[i]);
                int idx=((i-val)%n+n)%n;
                res[i]=nums[idx];
            }
        }
        return res;
    }
};