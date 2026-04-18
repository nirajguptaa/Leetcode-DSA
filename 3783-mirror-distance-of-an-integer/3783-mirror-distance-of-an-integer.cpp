class Solution {
public:
    int revNum(int n){
        int num=0;
        while(n>0){
            int r=n%10;
            n/=10;
            num=num*10+r;
        }
        return num;
    }
    int mirrorDistance(int n) {
        return abs(n-revNum(n));
    }
};