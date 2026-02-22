class Solution {
public:
    string binary(int n){
        if(n==0)return "0";
        string bin="";
        while(n>0){
            int r=n%2;
            n/=2;
            bin=to_string(r)+bin;
        }
        return bin;
    }
    int binaryGap(int n) {
        string bin=binary(n);
        int last=-1,ans=0;
        int l=bin.size()-1;
        for(int i=0;i<=l;i++){
            if(bin[i]=='1'){
                if(last!=-1){
                    ans=max(ans,i-last);
                    
                }
                last=i;
            }
        }
        return ans;
    }
};