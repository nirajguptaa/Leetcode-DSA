class Solution {
public:
    int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>bits(32,0);
        for(int x:nums){
            for(int i=0;i<32;i++){
                if(x & (1<<i)){
                    bits[i]++;
                }
            }
        }
        long long ans=0;
        while(k--){
            long long num=0;
            for(int i=0;i<32;i++){
                if(bits[i]>0){
                    num=num|(1LL<<i);
                    bits[i]--;
                }
            }
            ans=(ans+num*num)%mod;
        }
        return ans;
    }
};