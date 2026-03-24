class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxlen=0;
        auto expand=[&](int left,int right){
            while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
                if(right-left-1>maxlen){
                    maxlen=right-left-1;
                    start=left+1;
                }
            }
        };
        for(int i=0;i<s.length();i++){
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(start,maxlen);
    }
};