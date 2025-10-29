class Solution {
public:
    int binaryToint(string &binary){
        int num=0;
        for(char c:binary){
            num=num*2+(c-'0');
        }
        return num;
    }
    int smallestNumber(int n) {
        bitset<12>b(n);
        string binary=b.to_string();
        int s=binary.size();
        
        bool one=false;
        for(int i=0;i<s;i++){
            if(one==false && binary[i]=='0'){
               continue;
            }else if(binary[i]=='1'&& !one){
                one =true;
            }else{
                binary[i]='1';
            }
        }
        return binaryToint(binary);

        
    }
};