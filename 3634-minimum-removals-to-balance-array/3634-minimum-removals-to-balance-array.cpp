class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxlen=0;
        int left=0;
        for(int right=0;right<n;right++){
            while((long long)nums[left]*k<(long long)nums[right]){
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return n-maxlen;
    }
};