class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int ans=0;
        int pos=0;
        while(n>0){
            int bit=n&1;
            bit=bit^1;
            ans+=bit<<(pos);
            n=n>>1;
            pos++;
        }
        return ans;
    }
};