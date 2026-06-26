class Solution {
public:
    void f(int idx,vector<int>& nums,vector<vector<int>>&ans){
        int n=nums.size();
        if(idx==n){
            ans.push_back(nums);
            return ;
        }
        unordered_set<int>used;
        for(int start=idx;start<n;start++){
            if(used.count(nums[start])){
                continue;
            }
            used.insert(nums[start]);
            swap(nums[start],nums[idx]);
            
            f(idx+1,nums,ans);
            swap(nums[start],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        f(0,nums,ans);
        return ans;
    }
};