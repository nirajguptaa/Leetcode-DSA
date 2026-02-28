class Solution {
public:
    const int MOD=1e9+7;
    
    int concatenatedBinary(int n) {
        
        long long ans=0;
        int bitlen=0;

        for(int i=1;i<=n;i++){
            if((i & i-1)==0){
                bitlen++;
            }
            ans=((ans<<bitlen)%MOD+i)%MOD;    
        }
        return ans;
            
    }
};