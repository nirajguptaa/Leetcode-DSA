class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n);
        int k=0;
        for(int i=0,j=n;i<n && j<2*n;i++,j++){
            ans[k++]=nums[i];
            ans[k++]=nums[j];
        }
        return ans;

    }
};