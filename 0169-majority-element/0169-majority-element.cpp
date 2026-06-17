class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int ele=-1;
        int count=0;
        for(auto &p:mp){
            if(p.second>count){
                ele=p.first;
                count=p.second;
            }
        }
        return ele;
    }
};