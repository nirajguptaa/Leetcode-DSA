class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.length()!=s2.length()){
            return false;
        }
        int count[256]={0};
        for(int i=0;i<s1.length();i++){
            int offset=(i&1)<<7;
            count[offset+s1[i]]++;
            count[offset+s2[i]]--;
        }
        for(int i=0;i<256;i++){
            if(count[i]!=0){
                return false;
            }
        }
        return true;
    }
};