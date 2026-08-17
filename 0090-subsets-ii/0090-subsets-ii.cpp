class Solution {
public:
    void f(int idx,vector<int>&temp,vector<int>&nums,vector<vector<int>>&ans){
        int n=nums.size();
        if(idx==n){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[idx]);
        f(idx+1,temp,nums,ans);
        temp.pop_back();
        while(idx+1<n && nums[idx]==nums[idx+1]){
            idx++;
        }
        f(idx+1,temp,nums,ans);
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>temp;
        f(0,temp,nums,ans);
        return ans;
    }
};