class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if (n == 0) return 0;
        int l=0;
        unordered_map<char,int>mp;
        
        int maxlen=0;
        for(int r=0;r<n;r++){
            if(mp.find(s[r])!=mp.end()){
                l=max(l,mp[s[r]]+1);
            }
            mp[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
        
    }
};