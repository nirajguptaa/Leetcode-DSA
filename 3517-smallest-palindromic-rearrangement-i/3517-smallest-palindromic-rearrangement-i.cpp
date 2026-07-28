class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(),s.end());
        string first="",sec="";
        string odd="";
        int i=0;
        while(i<s.size()){
            if(s[i]==s[i+1]){
                first+=s[i];
                sec+=s[i];
                i+=2;
            }else{
                odd+=s[i];
                i+=1;
            }
        }
        reverse(sec.begin(),sec.end());
        return first+odd+sec;
    }
};