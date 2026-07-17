class Solution {
public:
    bool isPalin(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            string temp="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                if(isPalin(temp)){
                    count++;
                }
            }
        }
        return count;
    }
};