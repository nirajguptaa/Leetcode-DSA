class Solution {
public:
    void f(int i,vector<int>& nums,vector<vector<int>>&ans){
        int n=nums.size();
        if(i==n){
            ans.push_back(nums);
            return ;
        }
        for(int start=i;start<nums.size();start++){
            swap(nums[i],nums[start]);
           
            f(i+1,nums,ans);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        
        f(0,nums,ans);
        return ans;
    }
};