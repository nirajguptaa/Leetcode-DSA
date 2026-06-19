class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            ans<<=1;
            int lastbit=n&1;
            ans=ans|lastbit;
            n>>=1;
        }
        return ans;
    }
};