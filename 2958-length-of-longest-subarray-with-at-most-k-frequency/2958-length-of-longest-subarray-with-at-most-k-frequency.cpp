class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxlen=0;
        unordered_map<int,int>freq;
        int n=nums.size();
        int l=0,r=0;
        while(r<n){
            freq[nums[r]]++;
            if(freq[nums[r]]>k){
                while(l<=r && freq[nums[r]]>k){
                    freq[nums[l]]--;
                    l++;
                }
            }
            r++;
            maxlen=max(maxlen,r-l);

        }
        return maxlen;
    }
};