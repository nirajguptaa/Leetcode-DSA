class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int xorVal=0;
        for(int num:nums){
            xorVal^=num;
        }
        if(xorVal!=0){
            return nums.size();
        }
        for(int num:nums){
            if(num!=0){
                return nums.size()-1;
            }
        }
        return 0;


    }
};