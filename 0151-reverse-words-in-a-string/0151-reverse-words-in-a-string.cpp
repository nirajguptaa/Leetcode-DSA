class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int len=s.size()-1;
        while(len>=0){
            while(len>=0 && s[len]==' '){
                len--;
            }
            if(len<0)break;
            int i=len;
            while(i>=0 && s[i]!=' '){
                i--;
            }
            if(!ans.empty()){
                ans+=' ';
            }
            ans+=s.substr(i+1,len-i);
            len=i-1;
        }
        return ans;
    }
};