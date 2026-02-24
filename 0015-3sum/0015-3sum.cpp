class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int l=i+1;
            int h=n-1;
            while(l<h){
                int sum=nums[i]+nums[l]+nums[h];
                if(sum==0){
                    vector<int>temp={nums[i],nums[l],nums[h]};
                    ans.push_back(temp);
                    l++;
                    h--;
                    while(l<h && nums[l]==nums[l-1])l++;
                    while(l<h && nums[h]==nums[h+1])h--; 
                }else if(sum>0){
                    h--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};