class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int n:nums){
            freq[n]++;
        }
        for(auto f:freq){
            if(f.second>1){
                return f.first;
            }
        }
        return -1;
    }
};