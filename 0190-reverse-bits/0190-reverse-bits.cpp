class Solution {
    string intTObin(int n) {
        string bin="";
        if(n==0)return "0";
        while(n>0){
            bin+=(n%2)+'0';
            n/=2;
        }
        reverse(bin.begin(),bin.end());
        while (bin.size() < 32) {
            bin = "0" + bin;
        }
        return bin;
    }
    long long binTOint(string num){
        long long ans=0;
        for(int i=0;i<num.size();i++){
            ans=ans*2+(num[i]-'0');
        }
        return ans;
    }
public:
    int reverseBits(int n) {
        string bin=intTObin(n);
        reverse(bin.begin(),bin.end()); 
        int inte=binTOint(bin);
        return inte;
        
    }

};