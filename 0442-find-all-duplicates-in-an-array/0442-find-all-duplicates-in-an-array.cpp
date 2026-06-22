class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ele=abs(nums[i]);
            if(nums[ele-1]<0){
                ans.push_back(ele);
            }else{
                nums[ele-1]=-nums[ele-1];
            }
        }
        return ans;
    }
};