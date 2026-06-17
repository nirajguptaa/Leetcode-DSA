class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=-1,count=0;
        for(int num:nums){
            if(count==0){
                ele=num;
                count=1;
            }else if(num==ele){
                count++;
            }else{
                count--;
            }
        }
        int c=0;
        for(int num:nums){
            if(num==ele){
                c++;
            }
        }
        if(c>nums.size()/2){
            return ele;
        }
        return -1;
    }
};