class Solution {
public:
    void f(vector<int>&nums,int idx,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int start=idx;start<nums.size();start++){
            swap(nums[idx],nums[start]);
            f(nums,idx+1,ans);
            swap(nums[idx],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(nums,0,ans);
        return ans;
    }
};