class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0;
        int start=0;
        auto expand=[&](int left,int right){
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            int currlen=right-left-1;
            if(currlen>maxlen){
                maxlen=currlen;
                start=left+1;
            }
        };
        for(int i=0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(start,maxlen);
    }   
};