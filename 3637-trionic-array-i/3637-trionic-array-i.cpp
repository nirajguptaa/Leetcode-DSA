class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool p=false,q=false,n=false;
        int i=1;
        if(nums.size()<4)return false;
        while(i<nums.size()){
            if(!p){
                if(nums[i]>nums[i-1]){
                    p=true;
                }else{
                    return false;
                }
            }else if(p && !q){
                if(nums[i]<nums[i-1]){
                    q=true;
                }else if(nums[i]==nums[i-1]){
                    return false;
                }
            }else if(p && q && !n){
                if(nums[i]>nums[i-1]){
                    n=true;
                }else if(nums[i]==nums[i-1]){
                    return false;
                }
            }else if(n){
               if(nums[i]<=nums[i-1]){
                   return false;
               }
            }
            i++;
        }
        return p && q && n;
        
    }
};