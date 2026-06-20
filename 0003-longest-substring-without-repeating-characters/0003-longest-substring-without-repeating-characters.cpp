class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int n=s.size();
        unordered_map<char,int>mp;
        int l=0;
        int maxlen=INT_MIN;
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