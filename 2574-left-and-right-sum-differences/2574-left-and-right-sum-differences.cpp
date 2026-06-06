class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total=0;
        for(int x:nums){
            total+=x;
        }
        int leftSum=0;
        vector<int>ans;
        for(int x:nums){
            total-=x;
            ans.push_back(abs(leftSum-total));
            leftSum+=x;
        }
        return ans;
    }
};