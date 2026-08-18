class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int dist=0;
        int n=nums.size();
        for(int bit=0;bit<32;bit++){
            int ones=0;
            for(int num:nums){
                if(num &(1<<bit)){
                    ones++;
                }
            }
            int zeros=n-ones;
            dist+=ones*zeros;
        }
        return dist;
    }
};