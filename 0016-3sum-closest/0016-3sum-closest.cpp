class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int diff=INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int l = i + 1, h = n - 1;
            while (l < h) {
                int sum = nums[i] + nums[l] + nums[h];
                if (sum == target) {
                    return target;
                }
                if(abs(sum-target)<diff){
                    diff=abs(sum-target);
                    ans=sum;
                }
                if (sum < target) {
                    l++;
                } else {
                    h--;
                }
            }
        }
        return ans;
    }
};