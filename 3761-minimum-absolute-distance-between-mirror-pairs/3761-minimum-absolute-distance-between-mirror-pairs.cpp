class Solution {
public:
    int reverseNum(int n){
        int num=0;
        while(n>0){
            int r=n%10;
            n/=10;
            num=num*10+r;
        }
        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            int rev=reverseNum(nums[i]);
            mp[rev]=i;
        }
        
        return ans==INT_MAX?-1:ans;
    }
};