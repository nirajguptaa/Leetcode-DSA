class Solution {
public:
    void f(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res){
        int n=nums.size();
        if(idx==nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        f(idx+1,nums,temp,res);
        temp.pop_back();
        while(idx+1<n && nums[idx]==nums[idx+1]){
            idx++;
        }
        f(idx+1,nums,temp,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        f(0,nums,temp,res);
        return res;
    }
};