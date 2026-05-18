class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        bool sign=true;
        if(i<n && s[i]=='-'){
            sign=false;
            i++;
        }else if(i<n && s[i]=='+'){
            i++;
        }

        while(i<n && s[i]=='0'){
            i++;
        }
        long long ans=0;
        while(i<n && isdigit(s[i])){
            ans=ans*10+s[i]-'0';
            if(sign && ans>INT_MAX){
                return INT_MAX;
            }
            if(!sign && -ans<INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return int(sign==true?ans:-ans);
    }
};