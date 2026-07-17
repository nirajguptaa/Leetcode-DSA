class Solution {
public:
    int  isPalin(string s,int l,int r){
        int count=0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
            count++;
        }
        return count;
        
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            count+=isPalin(s,i,i);
            count+=isPalin(s,i,i+1);
        }
        return count;
    }
};