class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if (n == 0) return 0;
        int l=0,r=0;
        unordered_set<char>seen;
        
        int maxlen=0;
        while(r<n){
            while(r<n && !seen.count(s[r])){
                seen.insert(s[r]);
                r++;
            }
            maxlen=max(maxlen,r-l);
            seen.erase(s[l]);
            l++;
            
        }
        return maxlen;
        
    }
};