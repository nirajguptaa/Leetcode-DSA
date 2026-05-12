class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=0,ele2=0,cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1){
                cnt1++;
            }else if(nums[i]==ele2){
                cnt2++;
            }else if(cnt1==0){
                ele1=nums[i];
                cnt1=1;
                
            }else if(cnt2==0){
                ele2=nums[i];
                cnt2=1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        int limit=nums.size()/3;
        vector<int>ans;
        int count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1){
                count1++;
            }
            else if(nums[i]==ele2){
                count2++;
            }
        }
        if(count1>limit)ans.push_back(ele1);
        if(count2>limit)ans.push_back(ele2);
        return ans;
    }
};