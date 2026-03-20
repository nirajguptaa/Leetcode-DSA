class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int xorr=a^b;
            int andd=(a&b)<<1;
            a=xorr;
            b=andd;
        }
        return a;
    }
};