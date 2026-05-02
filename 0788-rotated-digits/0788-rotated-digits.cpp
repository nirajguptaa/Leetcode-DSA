class Solution {
public:
    bool diffnum(int d){
        return d==2 || d==5 || d==6 ||d==9;
    }
    bool validDig(int d){
        return d==0 || d==1 || d==2 || d==5|| d==6||d==8|| d==9;
    }
    bool validNum(int n){
        bool dnum=false;
        while(n>0){
            int r=n%10;
            if(validDig(r)==false){
                return false;
            }
            if(diffnum(r)){
                dnum=true;
            }
            n/=10;
        }
        return dnum && true;
    }
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=2;i<=n;i++){
            if(validNum(i)){
                ans++;
            }
        }
        return ans;
    }
};