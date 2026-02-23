class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                str+=tolower(s[i]);
            }
        }
        int l=0,h=str.size()-1;
        while(l<h){
            if(str[l]!=str[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
};