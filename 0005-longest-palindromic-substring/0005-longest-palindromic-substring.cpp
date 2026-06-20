class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxlen=0;
        auto expand=[&](int l,int r){
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            int currlen=r-l-1;
            if(currlen>maxlen){
                maxlen=currlen;
                start=l+1;
            }
        };
        for(int i=0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(start,maxlen);
    }
};