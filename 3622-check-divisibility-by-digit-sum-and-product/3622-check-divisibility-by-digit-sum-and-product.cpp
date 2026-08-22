class Solution {
public:
    bool checkDivisibility(int n) {
        int d=n;
        int digitSum=0;
        int productSum=1;
        while(n>0){
            int r=n%10;
            n/=10;
            digitSum+=r;
            productSum*=r;
        }
        int sum=digitSum + productSum;
        return (d%sum==0);
    }
};