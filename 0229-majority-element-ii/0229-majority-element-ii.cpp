class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto n:nums){
            freq[n]++;
        }
        int limit=nums.size()/3;
        vector<int>ans;
        for(auto it:freq){
            if(it.second>limit){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};