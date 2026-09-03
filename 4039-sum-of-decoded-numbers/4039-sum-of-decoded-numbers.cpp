class Solution {
public:
    long long power(long long x,long long y,long long mod){
        long long res=1;
        while(y>0){
            if(y%2==1){
                res=(res*x)%mod;
            }
            x=(x*x)%mod;
            y/=2;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        long long mod=1e9+7;
        long long sum=0;
        for(long long num:nums){
            int w=num%10;
            long long d=floor(num/10);
            string str=to_string(d);
            long long x=stoll(str.substr(0,w));
            long long y=stoi(str.substr(w));
            long long val=power(x,y,mod);
            sum=(sum+val)%mod;
            
        }
        return sum;
    }
};