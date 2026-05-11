class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=-1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(ele==-1){
                ele=nums[i];
                count+=1;
            }else if(nums[i]==ele){
                count++;
            }else{
                count--;
                if(count==0){
                    ele=-1;
                }
            }
        }
        return ele;
    }
};