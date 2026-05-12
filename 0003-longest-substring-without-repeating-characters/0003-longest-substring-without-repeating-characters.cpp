class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)return 0;
        int l=0;
        int maxlen=0;
        unordered_map<char,int>seen;
        for(int r=0;r<s.size();r++){
            if(seen.find(s[r])!=seen.end()){
                l=max(l,seen[s[r]]+1);
            }
            seen[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};