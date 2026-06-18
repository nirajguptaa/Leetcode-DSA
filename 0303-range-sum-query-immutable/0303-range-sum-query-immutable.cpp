class NumArray {
public:
    vector<int>prefSum;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefSum.resize(n+1);

       
        for(int i=0;i<nums.size();i++){
            prefSum[i+1]=prefSum[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefSum[right+1]-prefSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */